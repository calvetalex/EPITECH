import os


if os.name == "posix":  # Linux
    os.system("cp guimoku/__main__.py guimoku-manager")
    os.system("chmod +x guimoku-manager")
elif os.name == "nt":  # Windows
    os.system("python -m pip install pyinstaller")
    os.system("copy .\\guimoku\\__main__.py app.py")
    os.system("pyinstaller app.py --name guimoku-manager --onefile")
    os.system('copy .\\dist\\guimoku-manager.exe .')
