
#file one.py

def func():
    print("func() in one.py")

print("top-level in one.py")

if __name__ == "__main__":
	#Without the main sentinel, the code would be executed even if the script was imported as a module.
    print("one.py is being run directly")
else:
    print("one.py is being imported into another module")

