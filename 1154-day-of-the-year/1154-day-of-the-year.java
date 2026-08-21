class Solution {

    public int dayOfYear(String date) {

        int year = Integer.parseInt(date.substring(0, 4));
        int month = Integer.parseInt(date.substring(5, 7));
        int day = Integer.parseInt(date.substring(8, 10));

        int[] daysInMonth = {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        int total = 0;

        for (int i = 0; i < month - 1; i++) {
            total += daysInMonth[i];
        }

        // Add one day to February in a leap year
        if (month > 2 && isLeapYear(year)) {
            total++;
        }

        total += day;

        return total;
    }

    private boolean isLeapYear(int year) {

        if (year % 400 == 0) {
            return true;
        }

        if (year % 100 == 0) {
            return false;
        }

        return year % 4 == 0;
    }
}