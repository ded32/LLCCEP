; File type declaration
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

; Memory info type 
%struct.memory_info = type { 
	double*, 
	i64 
}

@__stderrp = external global %struct.__sFILE*, align 8
@.str = private unnamed_addr constant [48 x i8] c"Cannot allocate memory for heap information: %s\00", align 1
@.str.1 = private unnamed_addr constant [35 x i8] c"Error: invalid memory info pointer\00", align 1
@.str.2 = private unnamed_addr constant [35 x i8] c"Error: can't reallocate heap: %s!\0A\00", align 1

declare void @free(i8* nocapture)
declare i64 @fwrite(i8* nocapture, i64, i64, %struct.__sFILE* nocapture)
declare noalias i8* @calloc(i64, i64)
declare i32 @fprintf(%struct.__sFILE* nocapture, i8* nocapture readonly, ...)
declare i8* @"\01_strerror"(i32)
declare i32* @__error()
declare void @exit(i32)
declare noalias i8* @realloc(i8* nocapture, i64)

define noalias %struct.memory_info* @memory_init() {
	%1 = tail call i8* @calloc(i64 1, i64 16)
	%2 = icmp eq i8* %1, null
	br i1 %2, label %3, label %9

	%4 = load %struct.__sFILE*, %struct.__sFILE** @__stderrp, align 8, !tbaa !2
	%5 = tail call i32* @__error()
	%6 = load i32, i32* %5, align 4, !tbaa !6
	%7 = tail call i8* @"\01_strerror"(i32 %6)
	%8 = tail call i32 (%struct.__sFILE*, i8*, ...) @fprintf(%struct.__sFILE* %4, i8* nonnull getelementptr inbounds ([48 x i8], [48 x i8]* @.str, i64 0, i64 0), i8* %7)
	tail call void @exit(i32 1)
	unreachable

	%10 = bitcast i8* %1 to %struct.memory_info*
	ret %struct.memory_info* %10
}

define void @memory_write(%struct.memory_info*, i64, double) {
	%4 = icmp eq %struct.memory_info* %0, null
	br i1 %4, label %5, label %8

	%6 = load %struct.__sFILE*, %struct.__sFILE** @__stderrp, align 8, !tbaa !2
	%7 = tail call i64 @fwrite(i8* nonnull getelementptr inbounds ([35 x i8], [35 x i8]* @.str.1, i64 0, i64 0), i64 34, i64 1, %struct.__sFILE* %6)
	tail call void @exit(i32 1)
	unreachable

  %9 = getelementptr inbounds %struct.memory_info, %struct.memory_info* %0, i64 0, i32 1
  %10 = load i64, i64* %9, align 8, !tbaa !8
  %11 = icmp ugt i64 %10, %1
  br i1 %11, label %12, label %16

  %13 = getelementptr inbounds %struct.memory_info, %struct.memory_info* %0, i64 0, i32 0
  %14 = load double*, double** %13, align 8, !tbaa !11
  %15 = getelementptr inbounds double, double* %14, i64 %1
  store double %2, double* %15, align 8, !tbaa !12
  br label %31

  %17 = bitcast %struct.memory_info* %0 to i8**
  %18 = load i8*, i8** %17, align 8, !tbaa !11
  %19 = add i64 %1, 1
  %20 = tail call i8* @realloc(i8* %18, i64 %19)
  store i8* %20, i8** %17, align 8, !tbaa !11
  %21 = icmp eq i8* %20, null
  br i1 %21, label %22, label %28

  %23 = load %struct.__sFILE*, %struct.__sFILE** @__stderrp, align 8, !tbaa !2
  %24 = tail call i32* @__error()
  %25 = load i32, i32* %24, align 4, !tbaa !6
  %26 = tail call i8* @"\01_strerror"(i32 %25)
  %27 = tail call i32 (%struct.__sFILE*, i8*, ...) @fprintf(%struct.__sFILE* %23, i8* nonnull getelementptr inbounds ([35 x i8], [35 x i8]* @.str.2, i64 0, i64 0), i8* %26)
  tail call void @memory_free(%struct.memory_info* nonnull %0)
  tail call void @exit(i32 1) 
  unreachable

  %29 = bitcast i8* %20 to double*
  store i64 %19, i64* %9, align 8, !tbaa !8
  %30 = getelementptr inbounds double, double* %29, i64 %1
  store double %2, double* %30, align 8, !tbaa !12
  br label %31

  ret void
}

define void @memory_free(%struct.memory_info*) {
  %2 = icmp eq %struct.memory_info* %0, null
  br i1 %2, label %11, label %3

  %4 = getelementptr inbounds %struct.memory_info, %struct.memory_info* %0, i64 0, i32 0
  %5 = load double*, double** %4, align 8, !tbaa !11
  %6 = icmp eq double* %5, null
  br i1 %6, label %9, label %7

  %8 = bitcast double* %5 to i8*
  tail call void @free(i8* %8)
  br label %9

  %10 = bitcast %struct.memory_info* %0 to i8*
  tail call void @free(i8* %10)
  br label %11

  ret void
}

define double @memory_read(%struct.memory_info*, i64) {
  %3 = icmp eq %struct.memory_info* %0, null
  br i1 %3, label %4, label %7

  %5 = load %struct.__sFILE*, %struct.__sFILE** @__stderrp, align 8, !tbaa !2
  %6 = tail call i64 @fwrite(i8* nonnull getelementptr inbounds ([35 x i8], [35 x i8]* @.str.1, i64 0, i64 0), i64 34, i64 1, %struct.__sFILE* %5)
  tail call void @exit(i32 1)
  unreachable

  %8 = getelementptr inbounds %struct.memory_info, %struct.memory_info* %0, i64 0, i32 1
  %9 = load i64, i64* %8, align 8, !tbaa !8
  %10 = icmp ugt i64 %9, %1
  br i1 %10, label %11, label %14

  %12 = getelementptr inbounds %struct.memory_info, %struct.memory_info* %0, i64 0, i32 0
  %13 = load double*, double** %12, align 8, !tbaa !11
  br label %28

  %15 = bitcast %struct.memory_info* %0 to i8**
  %16 = load i8*, i8** %15, align 8, !tbaa !11
  %17 = add i64 %1, 1
  %18 = tail call i8* @realloc(i8* %16, i64 %17)
  store i8* %18, i8** %15, align 8, !tbaa !11
  %19 = icmp eq i8* %18, null
  br i1 %19, label %20, label %26

  %21 = load %struct.__sFILE*, %struct.__sFILE** @__stderrp, align 8, !tbaa !2
  %22 = tail call i32* @__error()
  %23 = load i32, i32* %22, align 4, !tbaa !6
  %24 = tail call i8* @"\01_strerror"(i32 %23)
  %25 = tail call i32 (%struct.__sFILE*, i8*, ...) @fprintf(%struct.__sFILE* %21, i8* nonnull getelementptr inbounds ([35 x i8], [35 x i8]* @.str.2, i64 0, i64 0), i8* %24)
  tail call void @memory_free(%struct.memory_info* nonnull %0)
  tail call void @exit(i32 1)
  unreachable

  %27 = bitcast i8* %18 to double*
  store i64 %17, i64* %8, align 8, !tbaa !8
  br label %28

  %29 = phi double* [ %13, %11 ], [ %27, %26 ]
  %30 = getelementptr inbounds double, double* %29, i64 %1
  %31 = load double, double* %30, align 8, !tbaa !12

  ret double %31
}
