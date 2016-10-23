declare double @llvm.pow.f64(double, double)
declare double @sin(double)
declare double @cos(double)
declare double @sqrt(double)
declare double @tan(double)
declare double @atan(double)

define double @getConstantToLoad(double) {
	%2 = fptoui double %0 to i64
	switch i64 %2, label %10 [
		i64 0, label %11
		i64 1, label %3
		i64 2, label %5
		i64 3, label %6
		i64 4, label %7
		i64 5, label %8
		i64 6, label %9
	}

; log2(10)
	%4 = tail call double @log2(double 1.000000e+01)
	br label %11

; log2(e)
	br label %11

; pi
	br label %11

; log10(2)
	br label %11

; ln(2)
	br label %11

; 0.0
	br label %11

; -1
	br label %11

; selection
	%12 = phi double [ -1.000000e+00, %10 ], [ 0.000000e+00, %9 ], 
	                 [ 0x3FE62E42FEFA39EF, %8 ], 
			 [ 0x3FD34413509F79FF, %7 ], 
			 [ 0x400921FB54442D18, %6 ], 
			 [ 0x3FF71547652B82FE, %5 ], 
			 [ %4, %3 ],
			 [ 1.000000e+00, %1 ]

	ret double %12
}
