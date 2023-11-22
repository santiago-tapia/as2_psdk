# Aerostack2 PSDK

## Installation

1) Create a ROS2 workspace [Create Workspace] (https://docs.ros.org/en/foxy/Tutorials/Beginner-Client-Libraries/Creating-A-Workspace/Creating-A-Workspace.html) or reuse a previous one.
2) Clone repository (somewhere in your ws):
```bash
git clone https://github.com/santiago-tapia/as2_psdk.git
```
3) Install source requirements (It takes a while because it has to download Payload SDK):
```bash
as2_psdk/install_requirements.sh
```

## Code format

Change from using .clang-format to ament_uncrustify:

* Download config file: 

```bash
wget https://raw.githubusercontent.com/ament/ament_lint/rolling/ament_uncrustify/ament_uncrustify/configuration/ament_code_style.cfg
mv ament_code_style.cfg uncrustify.cfg
```

* Download VS Code extension

Last seen is Uncrustify by Zachary Flower. Restart VS Code

* Activate option to format on saving file, go to: File -> Preference -> Settings -> Text Editor and
  mark the option "Format on Save".

* When editing a source file look for the brackets at the bottom, at the right of the text coding
  (usually UTF-8 LF), click on them and select uncrustify to format the code.
