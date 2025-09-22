from manim import *

bins = []

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
            arr_freq = arr[1:200]
            arr_freq_float = parseFloat(arr_freq)
            bins.append(arr_freq_float)

class Visualiser(Scene):
    def construct(self):
        readCSV()
        chart = BarChart(
            values=bins[0]
        )

        self.add(chart)
        for x in bins:
            self.play(chart.animate.change_bar_values(x), run_time=0.022)