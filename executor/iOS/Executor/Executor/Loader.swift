import Foundation

struct arg {
        var type: Character
        var value: Double
}

struct op {
        var cond_code: Character
        var op_code: Character
        var args:[arg]
}

func load()