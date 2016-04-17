import Foundation

struct arg {
        var type: UInt8
        var value: Double
}

struct op {
        var cond_code: UInt8
        var op_code: UInt8
        var args:[arg]
}

func load(var file:file_t) -> [op] {
        
}