<div id="start" align="center">
  <h1>Tattoo Power Supply (prototype)</h1>
  <p>Tattoo power supply prototype on diode led and potentiometer</p>
  <img src="https://img.shields.io/badge/espressif-E7352C?style=for-the-badge&logo=espressif&logoColor=white"/>
  <img src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/>
  <img src="https://img.shields.io/badge/PlatformIO-F5822A.svg?style=for-the-badge&logo=PlatformIO&logoColor=white"/>
</div>

## 📜 About The Project
TPS prototype on <b>ESP32-DevKit v1</b>. </br>
The diode led is "tattoo machine" and button is "footswitch".  </br>
In this project, the potentiometer controls the PWM of the LED. In reality, the power supply transmits the volts to the tattoo machine.  </br>
The footswitch (button) turns the tattoo machine on or off.
<h3>List of products:</h3>
<ul>
  <li>ESP32 DevKit v1</li>
  <li>Diode LED (red)</li>
  <li>Button (tact switch)</li>
  <li>Potentiometer</li>
  <li>Resistor 220Ω</li>
</ul>

## ✨ Features
- 🚨 You can change the brightness of the LED when it is off.

## 📸 Images
<p>x</p>
<!-- <div style="display: flex; flex-wrap: wrap; justify-content: center; gap: 10px;"> -->
  <!-- <img src="screenshots/none.png" style="width: 47%; max-width: 400px; border-radius: 8px;" /> -->
  <!-- <img src="screenshots/none.png" style="width: 47%; max-width: 400px; border-radius: 8px;" /> -->
  <!-- <img src="screenshots/none.png" style="width: 47%; max-width: 400px; border-radius: 8px;" /> -->
  <!-- <img src="screenshots/none.png" style="width: 47%; max-width: 400px; border-radius: 8px;" /> -->
<!-- </div> -->

## 🔧 Breadboard Configuration
<table>
  <tr>
    <td style="padding-right: 30px;">
      <img src="images/breadboard.jpg" width="400" style="border-radius: 8px;" />
    </td>
    <td>
      <h3>ESP32 → Potentiometer</h3>
      <ul>
        <li>3V3 → ?</li>
        <li>32 → ?</li>
        <li>GND → ?</li>
      </ul>
      <h3>ESP32 → Other</h3>
      <ul>
        <li>26 → Diode LED</li>
        <li>25 → Button</li>
      </ul>
      <p>Button and LED connect to GND</p>
      <p>LED resistor 220Ω</p>
    </td>
  </tr>
</table>

## 🛠️ Installation
<p>x</p>

## ✅ Run
Use <b>PlatformIO Serial Monitor</b> in VS Code + PlatformIO or other IDE

## 💡 How to use
Control the brightness of the LED using the potentiometer.   </br>
Turn on the LED using the button.

## 📝 TODO
- [ ] update photos
- [ ] update installation
- [ ] add LED