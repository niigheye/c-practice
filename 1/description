<h1 style = "font-size: 15;">Formulation of the problem. </h1>

Display the clock readings with analysis of the initial data.
The source data is hours and minutes in integer format.

The result should be presented in mixed text and numeric form:
2 48 – 2 hours 48 minutes at night,
5 00 – 5 o’clock in the morning exactly,
12 00 – noon,
12 23 – 12 hours 23 minutes of the day,
13 12 – 1 hour 13 minutes of the day,
21 33 – 9 hours 33 minutes in the evening,
00 00 – midnight,
03 01 – 3 hours 1 minute of the night.

Use the following day part boundaries:
5 o'clock <= morning < 12 noon,
12 <= day < 18 hours,
18 <= evening < 24 hours,
0 hour < night < 5 hours

If you enter impossible clock values, display a corresponding message, for example:
24 03 – invalid data entered.










<h1 style = "font-size: 15;">Algorithm development.</h1>
Description of the algorithm:
This algorithm displays the time entered by the user in text-numeric format. It takes into account the translation of clocks into the 12-hour format, as well as the preservation of cases of the words “hour”, “minute” in accordance with the rules of the Russian language, depending on the entered data, the time of day is saved (“morning”, “day”, “evening” ). In addition to this, there is a check for the correctness of the entered data, consideration of the case when the value of the minutes is equal to zero (the output of the word “exactly”).
Description of input, output and auxiliary data:
1) int hour – the variable stores data about the entered hours;
2) int min – the variable stores data about the entered minutes;
3) const char *h – variable storing the declension of the word “hour”;
4) const char *m – the variable stores the declination of the word “minute”;
5) const char *s – the variable stores the time of day;
