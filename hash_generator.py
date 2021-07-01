user_string = input("Type the string you want to generate the hash of: ")

string_hash = 0
for letter in user_string:
	string_hash += ord(letter)
	string_hash *= 100

print("The hash is " + str(string_hash))
