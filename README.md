# Spectra-View
A C++ and Manim based project that analyzes audio by computing the Discrete Fourier Transform (DFT) on short time windows of a WAV file. The FFT magnitudes are then exported to a CSV file and animated in Manim as dynamic bars.

## Demonstration
![Visualiser demo](./assets/vis.gif)

## Brief Overview
### What is a Fourier Transform?
The Fourier transform (FT) is an integral transform that takes a function as input, and outputs another function that describes the extent to which various frequencies are present in the original function.

The **Discrete Fourier Transform (DFT)** is a mathematical tool that converts a discrete sequence of data points from the time domain into a corresponding sequence in the frequency domain, breaking down a signal into its fundamental sinusoidal components.

The DFT thus proves useful to extract the frequencies present in digital audio files (like WAV!)

## Features / Roadmap
- [X] Read WAV files and processe raw PCM samples (from scratch)
- [X] Compute DFT on moving windows for time–frequency analysis
- [X] Use the manim library to dynamically display these frequency bars
- [] Build a real-time visualiser using OpenGL

## Resources
- [Coding Adventure: Sound](https://youtu.be/iA6wRgwl7k0?si=urdCEdR-AZQjt4Xy)
- [But what is a Fourier Transform? A visual introduction](https://youtu.be/spUNpyF58BY?si=UgOr_b3WYAmmJ-nl)