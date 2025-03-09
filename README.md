# cs216_l3_jb

Lab 3: Pointers Sort & Search

Description-

This project is a menu-driven application that manages a group of Creature objects within an Army class. It allows users to:

~~Print creatures in their original order.~~

~~Sort creatures by name or type in descending order.~~

~~Search for creatures by partial name or type (case-insensitive search).~~

Load creature data from an input file of unknown length.

Specifications and Requirements-

1. Class Design

~~Creature Class~~

~~Stores the name and type of the creature (stored in lowercase for case-insensitive searching).~~

~~Stores health and strength attributes.~~

~~Provides functions to return attributes and calculate damage.~~

Army Class

~~Manages an array of pointers to Creature objects.~~

~~Provides functions for loading, sorting, searching, and printing creatures.~~

2. Menu System (Implemented using enum and switch)

Main Menu

~~Print items in the original order.~~

~~Sort creatures (with submenu).~~

~~Search for creatures (by name or type).~~

~~Quit.~~

~~Sort Submenu~~

~~Sort by name (descending order).~~

~~Sort by type (descending order).~~

~~Return to the main menu.~~

~~Search Menu~~

~~Single option to search by name or type (case-insensitive, partial match).~~

~~If no matches are found, display an appropriate message.~~

3. Searching Implementation

~~One function must handle both name and type searches.~~

~~Uses partial search with std::find().~~

~~All names and types are stored in lowercase for easier comparisons.~~

4. Sorting Implementation

~~Bubble Sort must be used.~~

~~Sorting is done using pointers (swapping pointers instead of objects for efficiency).~~

~~No separate swap function; implement swapping directly inside the sorting function.~~

5. File Handling

~~Load records from an input file (unknown length).~~

~~No record validation (assume well-formed data).~~

~~Names and types may have mixed capitalization (convert to lowercase when reading).~~

Example format:

Elf  Rita  25 70
Troll  Grok  40 90

6. Output Formatting

~~Table format whenever possible.~~

~~Left-align text (names, types) and right-align numbers (health, strength).~~

~~Use consistent decimal places for numerical values.~~

Example output:

Name       Type     Health   Strength
-----------------------------------
elf        warrior    100       80
troll      brute      120      110
