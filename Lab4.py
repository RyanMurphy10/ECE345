import numpy as np
import matplotlib.pyplot as plt

frequency = np.array([23, 230, 2300, 23000, 230000]) #frequency
output_amplitude = np.array([90.05 * 0.001, 724.1 * 0.001, 989.5 * 0.001, 687.6 * 0.001, 34.16 * 0.001]) #Vout, Measured Amplitude
phase_shift = np.array([112, 43, -2, -46, -144]) #Measured Phase Shift

V_in = 1 #Vin

amplitude_dB = 20 * np.log10(output_amplitude / V_in) #dB Conversion
ideal_amplitude_dB = np.array([-20, 0, 0, 0, -20])
ideal_phase_shift = np.array([90, 45, 0, -45, -90]) #Ideal Phase shift

plt.figure(figsize=(10, 6))
plt.subplot(2, 1, 1)
plt.semilogx(frequency, amplitude_dB, marker = 'o', linestyle = '-', color = 'g', label = 'Experimental')
plt.semilogx(frequency, ideal_amplitude_dB, marker = 'o', linestyle = '-.', color = 'y', label = 'Idealized')
plt.xlabel('Frequency (Hz)')
plt.ylabel('Amplitude (dB)')
plt.title('Bode Plot: Amplitude')
plt.legend()
plt.yticks([20, 10, 0, -10, -20, -30, -40], ['20 dB', '10 dB', '0 dB', '-10 dB', '-20 dB', '-30 dB', '-40 dB'])
plt.xticks(frequency, ['23 Hz', '230 Hz', '2.3 kHz', '23 kHz', '230 kHz'])



plt.subplot(2, 1, 2)
plt.semilogx(frequency, phase_shift, marker = 'o', linestyle = '-', color = 'g', label = 'Experimental')
plt.semilogx(frequency, ideal_phase_shift, marker = 'o', linestyle = '-.', color = 'y', label = 'Idealized')
plt.xlabel('Frequency (Hz)')
plt.ylabel('Phase Shift (°)')
plt.title('Bode Plot: Phase Shift')
plt.legend()
plt.yticks([-135, -90, -45, 0, 45, 90, 135], ['-135', '-90°', '-45°', '0°', '45°', '90°', '135°'])
plt.xticks(frequency, ['23 Hz', '230 Hz', '2.3 kHz', '23 kHz', '230 kHz'])

plt.tight_layout()
plt.show()
