class Solution {
    public int daysBetweenDates(String date1, String date2) {
        int d1 = getDays(date1);
        int d2 = getDays(date2);

        return Math.abs(d1 - d2);
    }

    private int getDays(String date) {
        int year = Integer.parseInt(date.substring(0, 4));
        int month = Integer.parseInt(date.substring(5, 7));
        int day = Integer.parseInt(date.substring(8, 10));

        int total = 0;

        for (int y = 1971; y < year; y++) {
            total += isLeap(y) ? 366 : 365;
        }

        int[] days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        for (int m = 1; m < month; m++) {
            total += days[m - 1];
        }

        if (month > 2 && isLeap(year)) {
            total++;
        }

        return total + day;
    }

    private boolean isLeap(int year) {
        return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
    }
}