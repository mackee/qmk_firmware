#define PULSAR_H

#include "quantum.h"

#define encoder_update(clockwise) encoder_update_user(uint8_t index, clockwise)

#if defined(KEYBOARD_pulsar_rev1)
  #include "rev1.h"
#elif defined(KEYBOARD_pulsar_rev2)
  #include "rev2.h"
#endif // Pulsar revisions
