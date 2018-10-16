#pragma once

struct contact;

void addNote(contact *mas, const int numberOldNote, int &numberNewNote);

void interactiveWindow(void);

void printNote(contact *mas, const int numberOldNote, const int numberNewNote);

void saveNewNote(contact *mas, int &numberOldNote, int &numberNewNote);

void searchName(contact *mas, const int numberOldNote);

void searchNumber(contact *mas, const int numberOldNote);

void backButton(void);