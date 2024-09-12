# PhoneBook

A simple C++98 phonebook application that allows users to add contacts, search for contacts, and exit the program.

## Features

- Add new contacts (First Name, Last Name, Nickname, Phone Number, Darkest Secret)
- Search for contacts by index
- Display all contacts in a formatted table
- Exit the program

## Usage

Compile the program:
```bash
make
```

Run the program:
```bash
phonebook
```

## Commands

ADD: Add a new contact
SEARCH: Display contacts and search by index
EXIT: Exit the program

## Commands

- `ADD`: Add a new contact
- `SEARCH`: Display contacts and search by index
- `EXIT`: Exit the program

## Implementation Details

- Stores up to 8 contacts
- Replaces oldest contact when full
- Truncates fields to 10 characters when displaying

## Compilation

Compiled with:
```bash
c++ -Wall -Wextra -Werror -std=c++98
```

For more details on the implementation, refer to the source code.