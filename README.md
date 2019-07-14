# nodeMCU_motor
shield Motor for a NoceMCU

deadBand = 50 
Forward  : [              0 : 512 - deadBand ]
BackWard : [512 + deadBand  :           1023 ]

      MOTOR A     |   MOTOR B
      [0 : 511 ]  |  [ 0 : 511 ]
         [ 512 ]  |  [ 512 ] 
  [ 513 : 1023 ]  |  [ 513 : 1023 ]
  
CONTROL 
[RefSpd_A] [RefSpd_B] 


STATUS
[A_isMoving] [B_isMoving]

