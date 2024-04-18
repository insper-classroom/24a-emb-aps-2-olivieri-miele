import serial
import uinput

ser = serial.Serial('/dev/ttyACM0', 115200)

# Create new mouse device
device = uinput.Device([
    uinput.BTN_LEFT,
    uinput.BTN_RIGHT,
    uinput.REL_X,
    uinput.REL_Y,
    uinput.KEY_W,
    uinput.KEY_A,
    uinput.KEY_S,
    uinput.KEY_D,
    uinput.KEY_SPACE,
    uinput.KEY_LEFTSHIFT,
    uinput.KEY_R,
    uinput.KEY_E,
    uinput.KEY_Q,
    uinput.KEY_F,
])

num_2_key = {
    11: uinput.KEY_W, #W
    12: uinput.KEY_A, #A
    13: uinput.KEY_S, #S
    14: uinput.KEY_D, #D
    15: uinput.BTN_LEFT, #Fire
    16: uinput.KEY_LEFTSHIFT, #Aim
    17: uinput.KEY_SPACE, #Jump
    18: uinput.KEY_F, #Melee
    19: uinput.KEY_R,
    20: uinput.KEY_E,
    21: uinput.KEY_Q
}


def parse_data(data):
    axis = data[0]  # 0 for X, 1 for Y
    value = int.from_bytes(data[1:3], byteorder='little', signed=True)
    print(f"Received data: {data}")
    print(f"axis: {axis}, value: {value}")
    return axis, value


def move_mouse(axis, value):
    if axis == 0:    # X-axis
        device.emit(uinput.REL_X, value)
    elif axis == 1:  # Y-axis
        device.emit(uinput.REL_Y, value)

def press_key(axis, value):
    device.emit(num_2_key[axis], value)


def quick_press_key(axis):
    device.emit_click(num_2_key[axis])  # Pressiona a tecla


try:
    # sync package
    while True:
        print('Waiting for sync package...')
        while True:
            data = ser.read(1)
            if data == b'\xff':
                break

        # Read 4 bytes from UART
        data = ser.read(3)
        axis, value = parse_data(data)
        if (axis == 0 or axis == 1):
            move_mouse(axis, value)
        elif axis <= 16:
            press_key(axis, value)
        else:
            quick_press_key(axis) 

except KeyboardInterrupt:
    print("Program terminated by user")
except Exception as e:
    print(f"An error occurred: {e}")
finally:
    ser.close()
