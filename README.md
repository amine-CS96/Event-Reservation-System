
# Ticket Reservation System — Console-Based Ticket Booking Application in C

This C program is a command-line application designed to manage ticket reservations for events. It enables users to create, search, modify, display, and cancel reservations dynamically. The system practices dynamic memory management and modular programming, using structures to represent tickets and customers, ensuring a clean separation of concerns with separate source and header files.

---

## Features

* Create new events with a name, date, and total number of available seats.
* Book one or more tickets for an existing event.
* Cancel reservations partially or fully using a unique reservation code.
* Display all events with details such as date and available seats.
* Display all current reservations with user information.
* Search for events by name.
* Save events and reservations data into files.
* Load events and reservations data from files.
* Interactive console menu interface.

---

## Project Structure

```
Ticket-Reservation-System/
├── data/
│   ├── events.txt                # Saved events data file
│   └── reservations.txt          # Saved reservations data file
├── include/
│   └── reservation.h             # Header file with data structures and function prototypes
├── src/
│   ├── main.c                    # Main program with menu and user interaction
│   └── reservation.c             # Implementation of event and reservation management
└── README.md                     # This documentation file
```

---

## How to Compile

From the project root directory, compile with:

```bash
gcc src/main.c src/reservation.c -o reservation
```

---

## How to Run

After compilation, run the executable:

```bash
./reservation
```

You will see a menu with options like:

1. Add a new event
2. Book tickets for an event
3. Cancel a reservation
4. Show all events
5. Show all reservations
6. Search event by name
7. Save events to file
8. Save reservations to file
9. Load events from file
10. Load reservations from file
11. Quit

Follow the on-screen prompts to navigate and use the program.

---

## Data Structures

```c
typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

typedef struct {
    char nom[78];
    Date date;
    int nombre_places_total;
    int nombre_places_disponibles;
    int nombre_places_reservees;
} event;

typedef struct {
    char nom_event[78];
    char nom_complet[78];
    char code_reservation[5]; // Format: A00x
    int nombre_places_reservees;
} admin;
```

---

## Example Event Display

```
Event 1:
 Name           : Summer Concert
 Date           : 15/07/2025
 Total Seats    : 100
 Available Seats: 97
 Reserved Seats : 3
--------------------------
Event 2:
 Name           : Tech Conference
 Date           : 01/09/2025
 Total Seats    : 50
 Available Seats: 50
 Reserved Seats : 0
--------------------------
```

---

## Highlights & Learning Outcomes

* Dynamic memory management for flexible lists of events and reservations.
* File input/output for saving and loading data persistently.
* Modular code design separating interface (`main.c`) and logic (`reservation.c` + header).
* Implementation of interactive menus for user-friendly CLI.
* Use of structured data types and date management.
* Generation of unique reservation codes automatically.

---

## Limitations & Future Improvements

* Add input validation and error handling (e.g., invalid dates or seat numbers).
* Implement sorting and filtering of events and reservations.
* Add support for updating or modifying events and reservations.
* Improve user experience with clearer prompts and confirmations.
* Implement data encryption for saved files for privacy.
* Create a GUI or web front-end for easier access.

---

## License


This project is licensed under the MIT License — you are free to use, copy, modify, merge, publish, and distribute the software, provided that the original author is credited and the license notice is included in all copies or substantial portions of the software.

See the [LICENSE](LICENSE) file for full details.

---

