# VM configuration files reader

This module is one of the most important in the vm.
It reads your configuration files for VM startup.

Configuration files should look alike this one:
vm: {                                     # Config root 
	config: {                         # Config data
		screen: {                 # Screen config
			width: 800        # Screen width
			height: 640       # Screen height
		}

		ram: {                    # RAM config
			size: 536870912   # RAM size
		}

		devices: {                # Devices config
			dev: ["hdd0.lhd"] # HDD Device
		}
	}
}
