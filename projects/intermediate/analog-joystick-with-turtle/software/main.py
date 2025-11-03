import serial
import turtle
import time
import math

class JoystickController:
    # SETUP
    def __init__(self, port='COM4', baudrate=9600, max_speed=10, deadzone=100):
        self.ser = serial.Serial(port, baudrate)
        time.sleep(5)  # wait for the serial connection to initialize

        self.max_speed = max_speed
        self.deadzone = deadzone
        self.running = True

        self.turtle = turtle.Turtle()
        self.turtle.shape("turtle")
        self.turtle.speed(0)

        self.screen = turtle.Screen()
        self.screen.title("Moving in Turtle using Analog Joystick")
        self.screen.listen()
        self.screen.onkey(self.exit_program, "q")

    # FUNCTIONS

    def map_joystick(self, val, center=512, max_val=1023):
        if abs(val - center) < self.deadzone:
            return 0
        elif val > center:
            return (val - center - self.deadzone) / (max_val - center - self.deadzone)
        else:
            return -(center - val - self.deadzone) / (center - self.deadzone)
    
    def read_joystick(self):
        if self.ser.in_waiting > 0:
            line = self.ser.readline().decode('utf-8', errors="ignore").rstrip()
            parts = line.split(',')
            if len(parts) != 3:
                return None

            x_str, y_str, btn_str = parts
            return int(x_str), int(y_str), int(btn_str)
        return None
    
    def move_turtle(self, x_val, y_val):
        x_mapped = self.map_joystick(x_val)
        y_mapped = -self.map_joystick(y_val)

        # vector normalization
        magnitude = math.sqrt(x_mapped**2 + y_mapped**2)
        if magnitude > 0:
            x_norm = x_mapped / magnitude
            y_norm = y_mapped / magnitude

            speed = self.max_speed * min(magnitude, 1)

            t = self.turtle
            t.setheading(t.towards(t.xcor() + x_norm, t.ycor() + y_norm))
            t.forward(speed)

            print(f"Current speed: {round(speed, 2)}")

    def reset_turtle(self):
        self.turtle.clear()
        self.turtle.penup()
        self.turtle.home()
        self.turtle.pendown()
    
    def run(self):
        print("Press [Q] to quit the program.")
        self.update()
        self.screen.mainloop()

    def update(self):
        if self.running:
            joystick_data = self.read_joystick()
            if joystick_data:
                x_val, y_val, btn_val = joystick_data
                self.move_turtle(x_val, y_val)

                if btn_val == 1:
                    self.reset_turtle()
            self.screen.ontimer(self.update, 10)

    def exit_program(self):
        self.running = False
        self.ser.close()
        turtle.bye()
        exit(0)
    
# MAIN LOOP
if __name__ == "__main__":
    controller = JoystickController()
    controller.run()