@regs = common global [32 x double] zeroinitializer, align 16

define double* @getRegsPointer() {
  ret double* getelementptr inbounds ([32 x double], [32 x double]* @regs, i64 0, i64 0)
}
