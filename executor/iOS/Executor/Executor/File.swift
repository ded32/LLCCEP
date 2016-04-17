import Foundation

enum fmode: Int {
        case FMODE_READ    = 0
        case FMODE_WRITE   = 1
        case FMODE_INVALID = 2
}

class File {
        private var path: String
        private var buf: String
        private var mode: fmode
        private var ptr: UInt64
        
        internal init() {
                path = ""
                buf = ""
                mode = fmode.FMODE_INVALID
        }
        
        internal func open(var relPath: String, var fm: fmode) -> Self {
                path = relPath
                mode = fm
                
                if mode == fmode.FMODE_READ {
                        let content = NSString(contentsOfFile: path, encoding: NSUTF8StringEncoding,
                                               error: nil)
                        buf = content!
                } else if mode == fmode.FMODE_INVALID {
                        print("Error!\nCan't open with invalid fmode")
                        abort()
                }
                
                return self
        }
        
        internal func write(var data: String) -> Self {
                buf += data
                
                return self
        }
        
        func read() -> String {
                var res: String = ""
                
                while Int(is_space(buf[ptr])) {
                        
                }
                
                return res
        }
}