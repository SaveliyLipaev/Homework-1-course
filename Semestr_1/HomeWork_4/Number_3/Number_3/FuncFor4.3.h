#pragma once

struct Contact;

void addNote(Contact *mas, const int numberOldNote, int &numberNewNote);

void interactiveWindow(void);

void printNote(Contact *mas, const int numberOldNote, const int numberNewNote);

void saveNewNote(Contact *mas, int &numberOldNote, int &numberNewNote);

void searchName(Contact *mas, const int numberOldNote);

void searchNumber(Contact *mas, const int numberOldNote);

void backButton(void);