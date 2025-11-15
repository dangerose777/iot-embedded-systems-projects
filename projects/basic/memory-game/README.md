<div id="start" align="center">
  <h1>Memory Game</h1>
  <p>Repeat after me game</p>
  <img src="https://img.shields.io/badge/espressif-E7352C?style=for-the-badge&logo=espressif&logoColor=white"/>
  <img src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/>
  <img src="https://img.shields.io/badge/PlatformIO-F5822A.svg?style=for-the-badge&logo=PlatformIO&logoColor=white"/>
</div>

## 📜 About The Project
A simple game for remembering sequences on <b>ESP32-DevKitC</b>. </br>
<h3>List of products:</h3>
<ul>
  <li>ESP32 DevKit C</li>
  <li>4x Diode LED'S | Red, Yellow, Green, Blue</li>
  <li>4x Buttons (tact switch)</li>
  <li>4x Resistor 220Ω</li>
</ul>

## ✨ Features
- 📈 Scalable code for more LEDs.

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
      <h3>ESP32 → Diode Led's</h3>
      <ul>
        <li>4 → Red</li>
        <li>16 → Yellow</li>
        <li>17 → Green</li>
        <li>23 → Blue</li>
      </ul>
      <h3>ESP32 → Buttons</h3>
      <ul>
        <li>14 → Red</li>
        <li>27 → Yellow</li>
        <li>26 → Green</li>
        <li>25 → Blue</li>
      </ul>
      <p>All buttons and leds are connected to GND</p>
      <p>LED resistor 220Ω</p>
    </td>
  </tr>
</table>

## 🛠️ Installation
<p>x</p>

## ✅ Run
Use <b>PlatformIO Serial Monitor</b> in VS Code + PlatformIO or other IDE

## 💡 How to use
To start the game, click any button.  </br>
Click the buttons corresponding to the lights in the correct order.  </br>
If you click the wrong button, click any button to start over.  </br>
After winning, click any button to play again.  </br>

## 📝 TODO
- [ ] add global variable for number of LEDs
- [ ] update photos
- [ ] update installation
- [ ] add LCD
- [ ] add LED