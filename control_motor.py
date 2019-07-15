#code fonctionnel pour micropython

from machine import Pin, PWM

""" nodemcu pins from the motor shield """
enable_a = Pin(0, Pin.OUT)  # D1  PWM_A pulse
enable_b = Pin(2, Pin.OUT)  # D2  PWM_B pulse

pin_a = Pin(5, Pin.OUT)  # D3  PWM_A direction
pin_b = Pin(4, Pin.OUT)  # D4  PWM_B direction 


PWM_A = PWM(pin_a, freq=750)
PWM_B = PWM(pin_b, freq=750)

#----------------------------------------------

def speed(spd_a, spd_b):    # SPEED
PWM_A.duty(100)
PWM_B.duty(100)

def left():                 # LEFT
    enable_a.value(1)  
    enable_b.value(0)

def rigth():                # RIGHT
    enable_a.value(0)  
    enable_b.value(1)

def forward():              # FORWARD
    enable_a.value(0)  
    enable_b.value(0)  

def backward():             # BACKWARD
    enable_a.value(1)  
    enable_b.value(1)
