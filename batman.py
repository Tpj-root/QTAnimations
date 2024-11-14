import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QLabel, QVBoxLayout, QWidget
from PyQt5.QtGui import QMovie
from PyQt5.QtCore import Qt

app = QApplication(sys.argv)

# Create the main window
window = QMainWindow()

# Make the window transparent and always on top
window.setAttribute(Qt.WA_TranslucentBackground, True)
window.setWindowFlags(Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint)

# Create a central widget and set a layout
central_widget = QWidget()
layout = QVBoxLayout(central_widget)

# Add an animated GIF
label = QLabel()
movie = QMovie('gif/batman.gif')  # Relative path from the script
label.setMovie(movie)
movie.start()
layout.addWidget(label)

window.setCentralWidget(central_widget)

# Set a fixed size for the window if needed
window.setFixedSize(movie.currentPixmap().size())  # Resize the window to fit the GIF

# Move the window to the right side corner
screen_geometry = app.primaryScreen().geometry()
window_geometry = window.geometry()
right_x = screen_geometry.width() - window_geometry.width()  # X position for right side
bottom_y = screen_geometry.height() - window_geometry.height()  # Y position for bottom
window.move(right_x, bottom_y)

window.show()

# Start the event loop
sys.exit(app.exec())

