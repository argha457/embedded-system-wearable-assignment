Embedded System Engineer Assignment – Medoc Health
Overview
This project implements core firmware logic for a low-power wearable AI assistant. The solution focuses on energy efficiency, safe state management, and embedded system best practices using the C programming language.

System Design Summary
Dual-core SoC approach:
  Low-power core handles always-on wake-word detection.
  High-performance core wakes only for Wi-Fi and cloud communication.
Audio buffer calculation shows that a 10-second raw audio clip (~312 KB) exceeds the available 256 KB SRAM, requiring streaming or chunked buffering.
Hardware privacy is ensured using a physical mute switch that directly cuts microphone power, preventing any software override.

Firmware Logic
The firmware uses a switch-case state machine with three states:
  IDLE: Default state, LED OFF, audio OFF.
  LISTENING: Activated only when the button is pressed and battery >10%, LED GREEN, audio ON.
  ERROR: Triggered when battery <10%, LED RED, audio disabled.
Safety features include hold-to-talk behavior and a 30-second timeout to handle a stuck button condition.
