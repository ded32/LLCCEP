; File structure declaration
%struct.__sFILE = type { 
	i8*, 
	i32, 
	i32, 
	i16, 
	i16,
	%struct.__sbuf, 
	i32, 
	i8*, 
	i32 (i8*)*, 
	i32 (i8*, i8*, i32)*, 
	i64 (i8*, i64, i32)*, 
	i32 (i8*, i8*, i32)*, 
	%struct.__sbuf, 
	%struct.__sFILEX*, 
	i32, 
	[3 x i8], 
	[1 x i8], 
	%struct.__sbuf, 
	i32, 
	i64 
}

%struct.__sFILEX = type opaque

%struct.__sbuf = type { 
	i8*, 
	i32 
}

; Stack type declaration
%struct.stack = type { 
	double*, 
	i64 
}

; stderr file pointer
@__stderrp = external global %struct.__sFILE*, align 8

; String for telling about errors
@.str   = private unnamed_addr constant [36 x i8] c"Can't allocate memory for stack: %s\00", align 1
@.str.1 = private unnamed_addr constant [57 x i8] c"Invalid stack pointer: can't perform requested actions!\0A\00", align 1
@.str.2 = private unnamed_addr constant [37 x i8] c"Can't get top of stack: it's empty!\0A\00", align 1
@.str.3 = private unnamed_addr constant [35 x i8] c"Can't pop from stack: it's empty!\0A\00", align 1

declare noalias i8* @calloc(i64, i64)
declare i32 @fprintf(%struct.__sFILE* nocapture, i8* nocapture readonly, ...)
declare i8* @"\01_strerror"(i32)
declare i32* @__error()
declare void @exit(i32)
declare noalias i8* @realloc(i8* nocapture, i64)
declare void @free(i8* nocapture)
declare i64 @fwrite(i8* nocapture, i64, i64, %struct.__sFILE* nocapture)

; Function for stack creation
define noalias %struct.stack* @stack_init() {
  %1 = tail call i8* @calloc(i64 1, i64 16)
  %2 = icmp eq i8* %1, null
  br i1 %2, label %3, label %9
  
  %4 = load %struct.__sFILE*, %struct.__sFILE** @__stderrp, align 8, !tbaa !2
  %5 = tail call i32* @__error()
  %6 = load i32, i32* %5, align 4, !tbaa !6
  %7 = tail call i8* @"\01_strerror"(i32 %6)
  %8 = tail call i32 (%struct.__sFILE*, i8*, ...) @fprintf(%struct.__sFILE* %4, i8* nonnull getelementptr inbounds ([36 x i8], [36 x i8]* @.str, i64 0, i64 0), i8* %7)
  br label %11

  %10 = bitcast i8* %1 to %struct.stack*
  br label %11

  %12 = phi %struct.stack* [ %10, %9 ], [ null, %3 ]
  ret %struct.stack* %12
}


define void @stack_push(%struct.stack*, double) {
  %3 = icmp eq %struct.stack* %0, null
  br i1 %3, label %4, label %7

  %5 = load %struct.__sFILE*, %struct.__sFILE** @__stderrp, align 8, !tbaa !2
  %6 = tail call i64 @fwrite(i8* nonnull getelementptr inbounds ([57 x i8], [57 x i8]* @.str.1, i64 0, i64 0), i64 56, i64 1, %struct.__sFILE* %5)
  tail call void @exit(i32 1)
  unreachable

  %8 = bitcast %struct.stack* %0 to i8**
  %9 = load i8*, i8** %8, align 8, !tbaa !8
  %10 = getelementptr inbounds %struct.stack, %struct.stack* %0, i64 0, i32 1
  %11 = load i64, i64* %10, align 8, !tbaa !11
  %12 = add i64 %11, 1
  store i64 %12, i64* %10, align 8, !tbaa !11
  %13 = shl i64 %11, 3
  %14 = tail call i8* @realloc(i8* %9, i64 %13)
  %15 = bitcast i8* %14 to double*
  store i8* %14, i8** %8, align 8, !tbaa !8
  %16 = load i64, i64* %10, align 8, !tbaa !11
  %17 = add i64 %16, -1
  %18 = getelementptr inbounds double, double* %15, i64 %17
  store double %1, double* %18, align 8, !tbaa !12

  ret void
}

define double @stack_top(%struct.stack* readonly) {
  %2 = icmp eq %struct.stack* %0, null
  br i1 %2, label %3, label %6

  %4 = load %struct.__sFILE*, %struct.__sFILE** @__stderrp, align 8, !tbaa !2
  %5 = tail call i64 @fwrite(i8* nonnull getelementptr inbounds ([57 x i8], [57 x i8]* @.str.1, i64 0, i64 0), i64 56, i64 1, %struct.__sFILE* %4)
  tail call void @exit(i32 1)
  unreachable

  %7 = getelementptr inbounds %struct.stack, %struct.stack* %0, i64 0, i32 1
  %8 = load i64, i64* %7, align 8, !tbaa !11
  %9 = icmp eq i64 %8, 0
  br i1 %9, label %10, label %13

  %11 = load %struct.__sFILE*, %struct.__sFILE** @__stderrp, align 8, !tbaa !2
  %12 = tail call i64 @fwrite(i8* nonnull getelementptr inbounds ([37 x i8], [37 x i8]* @.str.2, i64 0, i64 0), i64 36, i64 1, %struct.__sFILE* %11)
  br label %19

  %14 = add i64 %8, -1
  %15 = getelementptr inbounds %struct.stack, %struct.stack* %0, i64 0, i32 0
  %16 = load double*, double** %15, align 8, !tbaa !8
  %17 = getelementptr inbounds double, double* %16, i64 %14
  %18 = load double, double* %17, align 8, !tbaa !12
  br label %19

  %20 = phi double [ %18, %13 ], [ 1.000000e+00, %10 ]
  ret double %20
}

define void @stack_pop(%struct.stack*) {
  %2 = icmp eq %struct.stack* %0, null
  br i1 %2, label %3, label %6

  %4 = load %struct.__sFILE*, %struct.__sFILE** @__stderrp, align 8, !tbaa !2
  %5 = tail call i64 @fwrite(i8* nonnull getelementptr inbounds ([57 x i8], [57 x i8]* @.str.1, i64 0, i64 0), i64 56, i64 1, %struct.__sFILE* %4)
  tail call void @exit(i32 1)
  unreachable

  %7 = getelementptr inbounds %struct.stack, %struct.stack* %0, i64 0, i32 1
  %8 = load i64, i64* %7, align 8, !tbaa !11
  %9 = icmp eq i64 %8, 0
  br i1 %9, label %10, label %13

  %11 = load %struct.__sFILE*, %struct.__sFILE** @__stderrp, align 8, !tbaa !2
  %12 = tail call i64 @fwrite(i8* nonnull getelementptr inbounds ([35 x i8], [35 x i8]* @.str.3, i64 0, i64 0), i64 34, i64 1, %struct.__sFILE* %11)
  br label %19

  %14 = bitcast %struct.stack* %0 to i8**
  %15 = load i8*, i8** %14, align 8, !tbaa !8
  %16 = add i64 %8, -1
  store i64 %16, i64* %7, align 8, !tbaa !11
  %17 = shl i64 %8, 3
  %18 = tail call i8* @realloc(i8* %15, i64 %17)
  store i8* %18, i8** %14, align 8, !tbaa !8
  br label %19

  ret void
}

define void @stack_delete(%struct.stack*) {
	%2 = icmp eq %struct.stack* %0, null
	br i1 %2, label %11, label %3

	%4 = getelementptr inbounds %struct.stack, %struct.stack* %0, i64 0, i32 0
	%5 = load double*, double** %4, align 8, !tbaa !8
	%6 = icmp eq double* %5, null
	br i1 %6, label %9, label %7

	%8 = bitcast double* %5 to i8*
	tail call void @free(i8* %8)
	tbr label %9

	%10 = bitcast %struct.stack* %0 to i8*
	tail call void @free(i8* %10)
	br label %11

	ret void
}
