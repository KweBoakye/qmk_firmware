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
SRC += keyrecords/combos.c
SRC += keyrecords/persistent_layers.c
SRC += keyrecords/taphold.c
SRC += pointing/pointing.c
SRC += callbacks.c


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
		  OPT_DEFS += -DCIRQUE_ENABLED
       endif
endif

ifeq ($(strip $(POINTING_ANALOG_JOYSTICK_ENABLE)), yes)
    OPT_DEFS += -DPOINTING_ANALOG_JOYSTICK_ENABLE
	SRC += analog.c
	SRC += pointing/analog_joystick_logic.c
endif

ifdef PMW3360_ENABLE
     ifeq ($(strip $(PMW3360_ENABLE)), yes)
         # SRC +=
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



COMBO_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes
