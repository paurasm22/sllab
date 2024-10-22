def encrypt_transposition(plaintext, key):
    # Initialize the ciphertext as an empty string
    ciphertext = ""

    # Loop over each column in the range of the key
    for col in range(key):
        # Go through the plaintext in steps of the key size
        for i in range(col, len(plaintext), key):
            # Add each character to the ciphertext
            ciphertext += plaintext[i]

    return ciphertext

# User input
plaintext = input("Enter the plaintext for Transposition Cipher: ")
key = int(input("Enter the key (number of columns): "))

# Encrypt
ciphertext = encrypt_transposition(plaintext, key)
print(f"Ciphertext: {ciphertext}")
