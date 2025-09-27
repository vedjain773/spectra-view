from manim import *
import math

bins = []

def changeHeight(new_vals: list):
    new_v_grp = VGroup()
    for i in range(0, len(new_vals)):
        line = Rectangle(height = new_vals[i], width = 0.01)
        new_v_grp += line

    new_v_grp.arrange(RIGHT, buff = 0.05)
    return new_v_grp

def parseFloat(arr: list):
    arr_new = [];
    for i in range (0, len(arr)):
        if arr[i] != '\n':
            arr_new.append(float(arr[i]))
    return arr_new

def readCSV():
    with open("/home/ved/Documents/spectra-view/data/freq.csv") as file:
        for line in file:
            arr = line.split(",")
            arr_freq = arr[1:]
            arr_freq_float = parseFloat(arr_freq)
            bins.append(arr_freq_float)

class Visualiser(Scene):
    def construct(self):
        readCSV()
        
        line_grp = VGroup()
        for i in range(0, len(bins[0])):
            line = Rectangle(height = 0.1, width = 0.01)
            line_grp += line

        line_grp.arrange(RIGHT, buff = 0.05)
        self.add(line_grp)

        for j in range(0, len(bins)):
            self.play(
                *[
                    rect.animate.stretch_to_fit_height(height)
                    for rect, height in zip(line_grp, bins[j])
                ],
                run_time=0.020
            )