kbd = Keyboard.new

kbd.init_pins(
  [ 9, 10, 11, 12, 14 ],             # row0, row1,... respectively
  [ 5, 4, 2, 3 ] # col0, col1,... respectively
)

kbd.add_layer :default, %i[
  KC_ESC  KC_KP_SLASH  KC_KP_ASTERISK  KC_KP_MINUS
  KC_KP_7  KC_KP_8  KC_KP_9   KC_KP_PLUS
  KC_KP_4  KC_KP_5  KC_KP_6   KC_KP_PLUS
  KC_KP_1  KC_KP_2  KC_KP_3   KC_KP_ENTER
  0_LOW    00       KC_KP_DOT KC_KP_ENTER
]

kbd.add_layer :lower, %i[
  KC_NO  RGB_HUI  RGB_HUD  KC_NO
  KC_NO  RGB_SAI  RGB_SAD  KC_NO
  KC_NO  RGB_VAI  RGB_VAD  KC_NO
  KC_NO  RGB_SPI  RGB_SPD  KC_NO
  0_LOW  RGB_MOD  RGB_RMOD  KC_NO
]

kbd.define_mode_key :0_LOW, [ :KC_KP_0, :lower, 150, 150 ]
kbd.define_composite_key :00,   %i(KC_KP_0 KC_KP_0)

encoder_1 = RotaryEncoder.new(27, 28)
encoder_1.clockwise do
  kbd.send_key :KC_1
end
encoder_1.counterclockwise do
  kbd.send_key :KC_2
end
kbd.append encoder_1

encoder_2 = RotaryEncoder.new(26, 22)
encoder_2.clockwise do
  kbd.send_key :KC_3
end
encoder_2.counterclockwise do
  kbd.send_key :KC_4
end
kbd.append encoder_2

encoder_3 = RotaryEncoder.new(21, 20)
encoder_3.clockwise do
  kbd.send_key :KC_5
end
encoder_3.counterclockwise do
  kbd.send_key :KC_6
end
kbd.append encoder_3

encoder_4 = RotaryEncoder.new(19, 18)
encoder_4.clockwise do
  kbd.send_key :KC_7
end
encoder_4.counterclockwise do
  kbd.send_key :KC_8
end
kbd.append encoder_4

encoder_5 = RotaryEncoder.new(17, 16)
encoder_5.clockwise do
  kbd.send_key :KC_9
end
encoder_5.counterclockwise do
  kbd.send_key :KC_0
end
kbd.append encoder_5

rgb = RGB.new(
  0,
  28,
  0,
  false
)
rgb.effect = :swirl
kbd.append rgb

kbd.start!
