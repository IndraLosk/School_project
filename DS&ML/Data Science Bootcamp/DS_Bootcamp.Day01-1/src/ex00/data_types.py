def data_types():
    var_int = 21
    var_str = "Hello"
    var_float = 2.1
    var_bool = True
    var_list = ["I have", 21, "dreams"]
    var_dict = {"name" : "Sia", "nickname" : "nilahugh"}
    var_tuple = (2, 1)
    var_set = {"H", "e", "l", "l", "o"}

    print("[", end = "")          
    print(type(var_int).__name__, type(var_str).__name__, type(var_float).__name__, type(var_bool).__name__, 
          type(var_list).__name__, type(var_dict).__name__, type(var_tuple).__name__, type(var_set).__name__,  sep=', ', end = "")
    print("]") 

if __name__ == '__main__':
    data_types()
