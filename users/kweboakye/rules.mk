SRC += kweboakye.c
SRC += definitions/keycodes.c
SRC += oled/oled.c
SRC += keyrecords/process_records.c
SRC += oled/helix.c
SRC += oled/smiley.c
SRC += oled/star.c
SRC += oled/roving_eye.c
SRC += oled/luna.c
SRC += oled/oled_utils.c
SRC += keyrecords/achordion.c
SRC += keyrecords/persistent_layers.c
SRC += keyrecords/taphold.c
SRC += keyrecords/os_toggle.c
#SRC += keyrecords/caps_word.c
SRC += keyrecords/num_word.c
SRC += keyrecords/nav_mode.c
SRC += keyrecords/select_word.c
SRC += keyrecords/casemodes.c
SRC += keyrecords/tap_dance.c

#SRC += keyrecords/default_mod_key.c
SRC += pointing/pointing.c
SRC += callbacks.c

COMBO_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes
CAPS_WORD_ENABLE = yes
TAP_DANCE_ENABLE = yes

ifeq ($(strip $(HAPTIC_ENABLE)), yes)
SRC += keyrecords/user_haptic.c
endif

ifeq ($(strip $(POINTING_DEVICE_ENABLE)), yes)
 SRC += pointing/pointing_utils.c
 SRC += $(QUANTUM_DIR)/pointing_device/pointing_device_gestures.c
endif
ifeq ($(strip $(OLED_ENABLE)), yes)
    #... your code here...

    ifdef OCEAN_DREAM_ENABLE
        ifeq ($(strip $(OCEAN_DREAM_ENABLE)), yes)
            SRC += oled/ocean_dream.c
            OPT_DEFS += -DOCEAN_DREAM_ENABLE
        endif
    endif
    ifndef OCEAN_DREAM_ENABLE
        SRC += oled/ocean_dream.c
        OPT_DEFS += -DOCEAN_DREAM_ENABLE
    endif
endif

ifdef CIRQUE_ENABLED
     ifeq ($(strip $(CIRQUE_ENABLED)), yes)
          SRC += pointing/cirque_trackpad_logic.c
		  SRC +=  drivers/sensors/cirque_pinnacle.c
		  SRC +=  drivers/sensors/cirque_pinnacle_i2c.c
		   SRC += drivers/sensors/cirque_pinnacle_gestures.c

		  OPT_DEFS += -DCIRQUE_ENABLED
       endif
endif

ifeq ($(strip $(POINTING_ANALOG_JOYSTICK_ENABLE)), yes)
    OPT_DEFS += -DPOINTING_ANALOG_JOYSTICK_ENABLE
	SRC += analog.c
	SRC += pointing/analog_joystick_logic.c

	SRC += drivers/sensors/analog_joystick.c
endif

ifdef PMW3360_ENABLE
     ifeq ($(strip $(PMW3360_ENABLE)), yes)
	      SRC += drivers/sensors/pmw3360.c
		  SRC += drivers/sensors/pmw33xx_common.c
          #SRC += pointing/trackball_logic.c
		  OPT_DEFS += -DPMW3360_ENABLE
       endif
endif

CUSTOM_SPLIT_TRANSPORT_SYNC ?= yes
ifeq ($(strip $(CUSTOM_SPLIT_TRANSPORT_SYNC)), yes)
    ifeq ($(strip $(SPLIT_KEYBOARD)), yes)
        QUANTUM_LIB_SRC += split/transport_sync.c
        OPT_DEFS += -DCUSTOM_SPLIT_TRANSPORT_SYNC
    endif

endif

CAPS_WORD_ENABLE ?= no
ifeq ($(strip $(CAPS_WORD_ENABLE)), yes)
    SRC += keyrecords/caps_word.c
    OPT_DEFS += -DCAPS_WORD_ENABLE
endif


COMBO_ENABLE ?= no
ifeq ($(strip $(COMBO_ENABLE)), yes)
    INTROSPECTION_KEYMAP_C = $(USER_PATH)/keyrecords/combos.c
endif
 




