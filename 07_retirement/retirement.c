#include <stdio.h>
#include <stdlib.h>

#define PERIOD 12

struct _retire_info {
  int months;
  double  contribution;
  double rate_of_return;
};

typedef struct _retire_info retire_info;  

double updateBalance (double balance, retire_info info) {
  double updatedBal =balance +  balance * info.rate_of_return + info.contribution;
  return updatedBal;
}

void printBalance(retire_info info, double bal, int ageMonths) {
  int year = ageMonths / PERIOD;
  int month = ageMonths % PERIOD;

  printf("Age %3d month %2d you have $%.2lf\n", year, month, bal);
}


void retirement (int startAge,   //in months
		 double initial, //initial savings in dollars
		 retire_info working, //info about working
		 retire_info retired){ //info about being retired 

  int retireAge = startAge + working.months;
  double updatedBal =  initial;
  for (int m = startAge; m<retireAge; m++){
    // update balance
    printBalance(working, updatedBal,  m);
      //printf("Age %3d month %2d you have $%.2lf\n", m/PERIOD, m, updatedBal);
    updatedBal =  updateBalance (updatedBal, working);
  }

  for(int m = retireAge; m < retireAge + retired.months; m++) {
    //printf("Age %3d month %2d you have $%.2lf\n", m/PERIOD, m, updatedBal);
    printBalance(retired, updatedBal,  m);
    updatedBal = updateBalance(updatedBal, retired);
  }

}

int main(void) {
  retire_info working = {489, 1000, 0.045 / PERIOD};
  retire_info retired = {384, -4000, 0.01 / PERIOD};

  retirement(327, 21345, working, retired);

  return 0;
}
