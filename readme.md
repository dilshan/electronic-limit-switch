## Electronic Limit Switch

This is an open-source fluid level control module designed for reliable and automated liquid management in tanks.

## Overview

This module can utilize two float-type limit switches or electronic sensor switches to detect fluid levels and control a relay accordingly. A microcontroller implements hysteresis logic to avoid unnecessary relay toggling caused by minor fluid level fluctuations, which enhances the system's reliability and lifespan.

## How It Works

1. The module monitors two limit switches:
   - *Upper limit switch (J1)*: Closes when the fluid level falls below the upper threshold.
   - *Lower limit switch (J2)*: Closes when the fluid level rises above the lower threshold.

2. Based on these inputs, the onboard microcontroller:
   - Activates or deactivates the relay.
   - Applies hysteresis logic to prevent rapid toggling.

3. The *J4 terminal block* provides:
   - AC mains input (up to 240V).
   - Relay output for controlling pumps or other devices.

## License

This is an open-source hardware project. All [design files](https://github.com/dilshan/electronic-limit-switch/tree/main/design), [documentation](https://github.com/dilshan/electronic-limit-switch/wiki), and [firmware source code](https://github.com/dilshan/electronic-limit-switch/tree/main/firmware) are available for download at the project source repository. The content of this project is distributed under the following licenses:

- Hardware license: [CERN-OHL-W](https://opensource.org/license/cern-ohl-w)
- Software license: [MIT License](https://github.com/dilshan/electronic-limit-switch?tab=MIT-1-ov-file)
- Documentation license: [CC BY 4.0](https://creativecommons.org/licenses/by/4.0)
