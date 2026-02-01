
# Hardware & System Architecture

## Low-Power Always-Listening Design

A dual-core SoC is used to maximize battery life:

* Low-Power Core (Core B):
  Always active, performs wake-word detection using lightweight DSP while consuming minimal power.

* High-Performance Core (Core A):
  Stays in deep sleep and wakes only after a wake-word trigger to handle Wi-Fi, audio buffering, and cloud communication.

This approach minimizes power usage during idle periods.

---

## Audio Buffer Memory Calculation

* 16 kHz, 16-bit, mono audio for 10 seconds
* Required memory:
  16,000 × 2 × 10 = 320,000 bytes (~312.5 KB)

With only 256 KB SRAM available, full buffering is not possible, so streaming or chunked buffering is required.

---

## Hardware Privacy (Hard Mute)

A physical hard-mute switch is placed in series with the microphone power line, ensuring the mic cannot be enabled by software under any condition.

---

## Summary

The design ensures low power consumption, secure user privacy, and efficient cloud interaction, suitable for wearable and medical-grade devices.

---

If you want it **even shorter (1-page style)** or more **diagram-focused**, I can do that too.
