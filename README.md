# ARK Survival File Checker for Cheat Detection

## Introduction

This ARK Survival File Checker is a tool designed for server administrators to detect popular cheat programs and unauthorized modifications within their ARK: Survival Evolved game server files. It helps ensure fair gameplay and maintain the integrity of your server by identifying any suspicious files or unauthorized changes made by players.

## Table of Contents
- [Getting Started](#getting-started)
- [System Requirements](#system-requirements)
- [Usage](#usage)
- [Features](#features)
- [Disclaimer](#disclaimer)
- [Contributing](#contributing)
- [License](#license)

## Getting Started

To get started with the ARK Survival File Checker, follow these steps:

1. **Download the Tool**: Clone or download this repository to your server machine.

2. **Installation**: No installation is required. Simply unzip the downloaded files to a location of your choice.

3. **Configuration**: Open the `config.json` file and modify any settings or file extensions you want to include in the check.

4. **Run the Tool**: Execute the file checker script. Ensure that you have the necessary permissions to access and scan your server's files.

## System Requirements

- Python 3.x
- Operating System: Windows, Linux, or macOS
- Admin access to the server and game files

## Usage

1. Run the tool in a command-line interface.

2. The tool will scan the specified game server directory for files with extensions matching those in the `config.json` file.

3. It will identify any files that match popular cheat program or unauthorized modification patterns.

4. The tool will display a report, listing the suspicious files found, their paths, and a brief description of why they are flagged.

5. As an admin, you can then take necessary actions such as investigating, banning, or reverting changes made by players to maintain server integrity.

## Features

- Customizable file extension filter.
- Detects popular cheat programs and unauthorized modifications.
- Generates a detailed report of suspicious files with explanations.
- Helps server admins maintain a cheat-free and fair gameplay environment.

## Disclaimer

This tool is provided as-is and may not be foolproof in detecting all cheat programs or unauthorized modifications. It is important to exercise good judgment and verify any findings manually. This tool is meant to assist server administrators in maintaining a cheat-free environment in ARK: Survival Evolved servers.

## Contributing

Contributions to this project are welcome. If you have ideas for improvements or new features, please feel free to open an issue or submit a pull request.

## License

This ARK Survival File Checker is licensed under the MIT License. For more details, please see the [LICENSE](LICENSE) file.

---

By using this tool responsibly and actively monitoring your ARK: Survival Evolved server files, you can help maintain a fair and enjoyable gaming experience for all players. If you encounter any issues or have suggestions for improvement, please don't hesitate to reach out and contribute to the project. Thank you for your commitment to fair gameplay!
