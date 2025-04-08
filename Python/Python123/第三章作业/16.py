s = "9e10"

try:
    # Check if string can be converted to float
    float(s)
    
    # Check if it's in float format
    if type(s) is str:
        if '.' in s or 'e' in s.lower():
            print(True)
        else:
            print(False)
    else:
        print(False)
except ValueError:
    print(False)
