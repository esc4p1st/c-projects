#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define FILMS_COUNT 10 
#define POPCORN_COUNT 4
#define DRINKS_COUNT 5
#define STUDENT_DISCOUNT 0.3
#define MEMBERSHIP_DISCOUNT 0.15

typedef enum
{
  INVALID, // 0
  YES, // 1
  NO, // 2
  GOHOME
} ENUMS;

typedef struct 
{
  const char* name_;
  float originalPrice; // 8 -> discount = 6
  float finalPrice; // 6
} Recommendation;


typedef struct 
{
  int movieChoice_;
  char student_;
  char membership_;
  int popcorn_;
  int drink_;
  char popcornInput_;
  char drinkInput_;
} Client;


void greetings()
{
  printf("===================================\n");
  printf("    Cinema Booking System\n");
  printf("===================================\n");
  printf(" \n");
}

void menu()
{
  printf("1. Purchase Ticket\n");
  printf("2. Movie Recommendation\n");
  printf("0. Exit\n");
}

void thankYouMessage()
{
  printf(" \n");
  printf("Thank you for visiting!\n");
  printf(" \n");
  printf("See you next time.\n");
}

void InvalidInputMessage()
{
  printf("---[Error]: Invalid option. Please enter from a number 0 to 2---\n");
}

void invalidMovieMessage()
{
  printf("---[Error]: Invalid Movie. Please enter from 1 to 10---\n");
}

void invalidInputYesOrNoMessage()
{
  printf("---[Error]: Invalid Input. Please Enter y or n---\n");
}

void invalidInputDrinkMessage()
{
  printf("---[Error]: Invalid Input. Please Enter from 1 to 5---\n");
}

void invalidInputPopcornMessage()
{
  printf("---[Error]: Invalid Input. Please Enter from 1 to 4---\n");
}

void invalidInputBudget()
{
  printf("---[Error]: Invalid Input. Please Enter Number---\n");
}

void chooseMovieMessage()
{
  printf("Choose a movie\n"); // void chooseMoviesMessage
}

void askPopcornMessage()
{
  printf("Would you like Popcorn?\n");
  printf("(y/n)\n");
}

void askDrinkMessage()
{
  printf("Would you like something to drink?\n");
  printf("(y/n)\n");
}

void askMembershipMessage()
{
  printf("Do you have a membership card?\n");
  printf("(y/n)\n");
}

void askStudentMessage()
{
  printf("Are you a student?\n");
  printf("(y/n)\n");
}

void printingMovies(const char* films[10], const float prices[10])  // standard
{
  printf("=========== MOVIES ===========\n");
  printf(" \n");
  for(int i = 0; i < 10; i++)
  {
    printf("%d. %s - %.2f EUR\n", i + 1, films[i], prices[i]);
  }
  printf(" \n");
}

void drinksMessage(const char* drinks[DRINKS_COUNT], const float drinksPrices[DRINKS_COUNT])
{
  printf("=========== DRINKS ===========");
  printf(" \n");
  for(int i = 0; i < DRINKS_COUNT; i++)
  {
    printf("%d. %s\n", i + 1, drinks[i]);
  }
  printf("Please choose a drink\n");
}

void popcornArray(const char* popcorns[POPCORN_COUNT], const float popcornPrices[POPCORN_COUNT])
{
  // use parameters
  printf("=========== POPCORN ===========\n");
  printf(" \n");
  for(int i = 0; i < 4; i++)
  {
    printf("%d. %s\n", i + 1, popcorns[i]);
  }
  printf("Please choose a popcorn\n");
}

int askDrinkMenuInput(Client* clientChoice)
{
  int drinkChoiceInput;
  // scanf("%d", &drinkChoiceInput);
  if(scanf("%d", &drinkChoiceInput) != 1)
  {
    invalidInputDrinkMessage();
    while (getchar() != '\n');
    return INVALID;
  }
  if(drinkChoiceInput == 0)
  {
    invalidInputDrinkMessage();
    return INVALID;
  }
  if(drinkChoiceInput > 5)
  {
    invalidInputDrinkMessage();
    return INVALID;
  }
  clientChoice->drink_ = drinkChoiceInput;
  return drinkChoiceInput;

  // TODO Make a validation
}

int askPopcornMenuInput(Client* clientChoice)
{
  int popcornChoiceInput;
  // scanf("%d", &popcornChoiceInput);
  if(scanf("%d", &popcornChoiceInput) != 1)
  {
    invalidInputPopcornMessage();
    while (getchar() != '\n');
    return INVALID;
  }
  if(popcornChoiceInput == 0)
  {
    invalidInputPopcornMessage();
    return INVALID;
  }
  if(popcornChoiceInput > 4)
  {
    invalidInputPopcornMessage();
    return INVALID;
  }
  clientChoice->popcorn_ = popcornChoiceInput;
  // TODO make a validation
}

int askMovieInput(Client* clientChoice)
{
  int movieChoice;
  //scanf("%c", &movieChoice);
  if(scanf("%d", &movieChoice) != 1)
  {
    invalidMovieMessage();
    while (getchar() != '\n');
    return INVALID;
  }
  if(movieChoice > 10 || movieChoice < 1)
  {
    invalidMovieMessage();
    return INVALID;
  }
  // if(isdigit(movieChoice) == 0)
  // {
  //   invalidMovieMessage();
  //   return INVALID;
  // }
  clientChoice->movieChoice_ = movieChoice;
  return YES; //success
}

int askDrinkInput(const char* drinks[DRINKS_COUNT], const float drinksPrices[DRINKS_COUNT], Client* clientChoice)
{
  char drinksAnswer;
  scanf(" %c", &drinksAnswer);
  clientChoice->drinkInput_ = drinksAnswer;
  if(drinksAnswer != 'y' && drinksAnswer != 'n')
  {
    invalidInputYesOrNoMessage();
    return INVALID;
  }
  if(drinksAnswer == 'y')
  {
    // clientChoice->drinkInput_ = drinksAnswer;
    return YES;
  }
  if(drinksAnswer == 'n')
  {
    return NO;
  }
}

int askPopcornInput(Client* clientChoice)
{
  char popcornAnswer;
  askPopcornMessage();
  //int popcornChoice;
  scanf(" %c", &popcornAnswer);
  clientChoice->popcornInput_ = popcornAnswer;
  if(popcornAnswer == 'y')
  {
    // clientChoice->popcornInput_ = popcornAnswer;
    return YES;
    //scanf("%d", &popcornChoice);
  }
  if(popcornAnswer == 'n')
  {
    return NO;
  }
  if(popcornAnswer != 'y' && popcornAnswer != 'n')
  {
    invalidInputYesOrNoMessage();
    return INVALID;
  }
  // clientChoice->popcornInput_ = popcornAnswer;
}

int askStudentInput(Client* clientChoice) // изменил войд на флоат чтобы возвращала сумму скидки
{
  char discountCard;
  askStudentMessage();
  // clientChoice->student_ = discountCard;
  scanf(" %c", &discountCard);
  clientChoice->student_ = discountCard;
  if(discountCard == 'y')
  {
    // clientChoice->student_ = discountCard;
    return YES;
  }
  if(discountCard == 'n')
  {
    return NO;
  }
  if(discountCard != 'y' && discountCard != 'n')
  {
    invalidInputYesOrNoMessage();
    return INVALID;
  }
  // clientChoice->student_ = discountCard;
}

int askMembershipInput(Client* clientChoice)
{
  char membership;
  askMembershipMessage();
  scanf(" %c", &membership);
  clientChoice->membership_ = membership;
  if(membership == 'y')
  {
    //clientChoice->membership_ = membership;
    return 1;
  }
  if(membership == 'n')
  {
    return 2;
  }
  if(membership != 'y' && membership != 'n')
  {
    invalidInputYesOrNoMessage();
    return INVALID;
  }
}

int askBudgetInput()
{
  int budget;
  printf("Please Enter Your Budget:\n");
  // scanf("%d", &budget);
  return budget;
}


void receipt(Client clientChoice, const char* films[FILMS_COUNT], const float prices[10], 
                      const char* popcorns[POPCORN_COUNT], const float popcornPrices[POPCORN_COUNT],
                      const char* drinks[DRINKS_COUNT], const float drinksPrices[DRINKS_COUNT])
{
  int movie = clientChoice.movieChoice_;
  char discountCard = clientChoice.student_;
  char membership = clientChoice.membership_;
  int popcorn = clientChoice.popcorn_;
  char popcornResult = clientChoice.popcornInput_;
  char drinkResult = clientChoice.drinkInput_;
  int drink = clientChoice.drink_;

  printf("=========== RECEIPT ===========");
  printf("\n");
  printf("Movie:\n");
  printf("%s\n", films[movie - 1]);
  printf("\n");
  printf("Ticket:\n");
  printf("%.2f EUR\n", prices[movie - 1]);
  printf("\n");
  printf("Discount:\n");
  if(discountCard == 'y')
  {
    float studentDiscount = prices[movie - 1] * STUDENT_DISCOUNT;
    printf("-%.2f EUR\n", studentDiscount);
  }
  if(membership == 'y')
  {
    float membershipDiscount = prices[movie - 1] * MEMBERSHIP_DISCOUNT;
    printf("-%.2f EUR\n", membershipDiscount);
  }
  if(discountCard == 'n' && membership == 'n')
  {
    printf("None\n");
  }
  printf("\n");
  printf("Popcorn:\n");
  if(popcornResult == 'y')
  {
    printf("%s %.2f EUR\n", popcorns[popcorn - 1], popcornPrices[popcorn - 1]);
  }
  if(popcornResult == 'n')
  {
    printf("None\n");
  }
  printf("\n");
  printf("Drink:\n");
  if(drinkResult == 'y')
  {
    printf("%s %.2f EUR\n", drinks[drink - 1], drinksPrices[drink - 1]);
  }
  if(drinkResult == 'n')
  {
    printf("None\n");
  }
  printf("\n");
  printf("-------------------------------\n");
  printf("\n");
  printf("TOTAL:\n");
  float TOTAL;
  if(discountCard == 'y' && popcornResult == 'y' && drinkResult == 'y')
  {
    float TOTAL = prices[movie - 1] * (1.0 - STUDENT_DISCOUNT) + popcornPrices[popcorn - 1] + drinksPrices[drink - 1];
    printf("%.2f EUR\n", TOTAL);
  }
  if(discountCard == 'n' && membership == 'y' && popcornResult == 'y' && drinkResult == 'y')
  {
    float TOTAL = prices[movie - 1] * (1.0 - MEMBERSHIP_DISCOUNT) + popcornPrices[popcorn - 1] + drinksPrices[drink - 1];
    printf("%.2f EUR\n", TOTAL);
  }
  if(discountCard == 'n' && membership == 'n' && popcornResult == 'y' && drinkResult == 'y')
  {
    float TOTAL = prices[movie - 1] + popcornPrices[popcorn - 1] + drinksPrices[drink - 1];
    printf("%.2f EUR\n", TOTAL);
  }
  if(discountCard == 'y' && popcornResult == 'n' && drinkResult == 'y')
  {
    float TOTAL = prices[movie - 1] * (1.0 - STUDENT_DISCOUNT) + drinksPrices[drink - 1];
    printf("%.2f EUR\n", TOTAL);
  }
  if(discountCard == 'y' && popcornResult == 'y' && drinkResult == 'n')
  {
    float TOTAL = prices[movie -1] * (1.0 - STUDENT_DISCOUNT) + popcornPrices[popcorn - 1];
    printf("%.2f EUR\n", TOTAL);
  }
  if(discountCard == 'y' && popcornResult == 'n' && drinkResult == 'n')
  {
    float TOTAL = prices[movie - 1] * (1.0 - STUDENT_DISCOUNT);
    printf("%.2f EUR\n", TOTAL);
  }
  if(membership == 'y' && popcornResult == 'n' && drinkResult == 'n')
  {
    float TOTAL = prices[movie - 1] * (1.0 - MEMBERSHIP_DISCOUNT);
    printf("%.2f EUR\n", TOTAL);
  }
  if(membership == 'y' && popcornResult == 'n' && drinkResult == 'y')
  {
    float TOTAL = prices[movie - 1] * (1.0 - MEMBERSHIP_DISCOUNT) + drinksPrices[drink - 1];
    printf("%.2f EUR\n", TOTAL);
  }
  if(membership == 'y' && popcornResult == 'y' && drinkResult == 'n')
  {
    float TOTAL = prices[movie - 1] * (1.0 - MEMBERSHIP_DISCOUNT) + popcornPrices[popcorn - 1];
    printf("%.2f EUR\n", TOTAL);
  }
  if(discountCard == 'n' && membership == 'n' && popcornResult == 'y' && drinkResult == 'n')
  {
    float TOTAL = prices[movie - 1] + popcornPrices[popcorn - 1];
    printf("%.2f EUR\n", TOTAL);
  }
  if(discountCard == 'n' && membership == 'n' && popcornResult == 'n' && drinkResult == 'y')
  {
    float TOTAL = prices[movie - 1] + drinksPrices[drink - 1];
    printf("%.2f EUR\n", TOTAL);
  }
  if(discountCard == 'n' && membership == 'n' && popcornResult == 'n' && drinkResult == 'n')
  {
    float TOTAL = prices[movie - 1];
    printf("%.2f EUR\n", TOTAL);
  }
  printf("\n");
  printf("Enjoy Your Movie!\n");
}

void purchasingTicket(const char* films[FILMS_COUNT], const float prices[10], 
                      const char* popcorns[POPCORN_COUNT], const float popcornPrices[POPCORN_COUNT],
                      const char* drinks[DRINKS_COUNT], const float drinksPrices[DRINKS_COUNT])
{
  Client clientChoice = {0};
  printingMovies(films, prices);
  chooseMovieMessage();

  while(1)
  {
    int movie = askMovieInput(&clientChoice);
    // printf("%d\n", clientChoice.movieChoice_);
    if(movie == YES)
    {
      break;
    }
  }

  int student;

  while(2) // Big O notation. Loop inside of loop inside of loop x2 running
  {
    student = askStudentInput(&clientChoice);
    // printf("%c\n", clientChoice.student_);
    if(student == YES)
    {
      break;
    }
    if(student == NO)
    {
      break;
    }
    if(student != YES && student != NO)
    {
      invalidInputYesOrNoMessage();
    }
  }
 
  //student == 2
  while(student == NO) // 2
  {
    int membership = askMembershipInput(&clientChoice);
    if(membership == YES || membership == NO)
    {
      break;
    }
  }

  while(4)
  {
    int popcorn = askPopcornInput(&clientChoice);
    if(popcorn == YES)
    {
      popcornArray(popcorns, popcornPrices);
      int popcorn_menu = askPopcornMenuInput(&clientChoice);
      if(popcorn_menu == INVALID)
      {
        continue;
      }
      break;
    }
    if(popcorn == NO)
    {
      break;
    }
  }

  while(5)
  {
    askDrinkMessage();
    int drink = askDrinkInput(drinks, drinksPrices, &clientChoice);
    if(drink == YES)
    {
      drinksMessage(drinks, drinksPrices);
      int drinksMenu = askDrinkMenuInput(&clientChoice);
      if(drinksMenu == INVALID)
      {
        continue;
      }
      // printf("%d\n", clientChoice.drink_);
      break;
    }
    if(drink == NO)
    {
      break;
    }
  }
  receipt(clientChoice, films, prices, popcorns, popcornPrices, drinks, drinksPrices);
}

// TODO Write InsertionSort algorithm
// TODO Fix the finalPrice for Reco Mode
void insertionSort(Recommendation arr[], int count) 
{
  for (int i = 1; i < count; i++)
  {
    Recommendation key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j].finalPrice > key.finalPrice) 
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
    }
}

void recommendation(const char* films[FILMS_COUNT], const float prices[10])
{
  Client clientChoice = {0};
  Recommendation recommendationMovies[FILMS_COUNT];
  int count = 0;
  int budget = askBudgetInput();
  float discount = 0.0;
  if(scanf("%d", &budget) != 1)
  {
    invalidInputBudget();
    while (getchar() != '\n');
    // return askBudgetInput();
    return recommendation(films, prices);
  }
  if(budget < 2)
  {
    printf("Please Go Home\n");
    return;
  }
  if(budget >= 2)
  {
    printf("You are more than welcome to watch movies\n");
    // int isStudent = askStudentInput(&clientChoice);
    clientChoice.student_ = askStudentInput(&clientChoice); // 30% discount
    if(clientChoice.student_ == YES)
    {
      discount = STUDENT_DISCOUNT;
    }
    if(clientChoice.student_ == NO) 
    {
      clientChoice.membership_ = askMembershipInput(&clientChoice); // 15% discount
      discount = MEMBERSHIP_DISCOUNT;
    }
  }
  for(int i = 1; i < FILMS_COUNT; i++) // i = 1  Interstellar = 10
  {
    float finalPrice = prices[i] * (1.0 - discount); // 7
    if(finalPrice <= budget)
    {
      recommendationMovies[count].name_ = films[i]; // 0 = interstellar
      recommendationMovies[count].originalPrice = prices[i]; // 10
      recommendationMovies[count].finalPrice = finalPrice; // 7
      count++; // 5
    } 
  }
  insertionSort(recommendationMovies, count);
  printf("=========== RECOMMENDATION MODE ===========\n");
  for(int i = 0; i < count; i++)
  {
    printf("%d. %s - %.2f EUR\n", i + 1, recommendationMovies[i].name_, recommendationMovies[i].finalPrice);
  }
}

void logic(const char* films[FILMS_COUNT], const float prices[10], 
                      const char* popcorns[POPCORN_COUNT], const float popcornPrices[POPCORN_COUNT],
                      const char* drinks[DRINKS_COUNT], const float drinksPrices[DRINKS_COUNT])
{
  int decision;
  while(1)
  {
    greetings();
    menu();
    // scanf("%d", &decision);
    if(scanf("%d", &decision) != 1)
    {
      InvalidInputMessage();
      while (getchar() != '\n');
      continue;
    }
    if(decision == 0)
    {
      thankYouMessage();
      break;
    }
    if(decision == 1)
    {
      purchasingTicket(films, prices, popcorns, popcornPrices, drinks, drinksPrices);
      continue;
    }
    if(decision == 2)
    {
      recommendation(films, prices);
      // TODO We need an infinite asking after recomendation mode
      continue; // i = 0; i = 1
      //
    }
    if(decision != 0 && decision != 1 && decision != 2)
    {
      InvalidInputMessage();
    }
  }
}

int main()
{
  const char* films[FILMS_COUNT] = {
  "Gladiator",
  "The Green Mile",
  "Saving Private Ryan",
  "The Prestige",
  "Whiplash",
  "The Silence of the Lambs",
  "Se7en",
  "Joker",
  "Parasite",
  "Oppenheimer"
  };
  const float prices[FILMS_COUNT] = {
    10.00, //10
    15.00, 
    4.00, 
    228.00, 
    2.00, 
    9.00, 
    12.00, 
    9.00, 
    7.00, 
    20.00
  };
  const float drinksPrices[DRINKS_COUNT] = {
    3.50,
    5.00,
    2.50,
    4.50,
    1.00
  };
  const char* drinks[DRINKS_COUNT] = {
    "Cola",
    "Sprite",
    "Water",
    "Ice Tea",
    "Orange Juice"
  };
  const char* popcorns[POPCORN_COUNT] = {
  "Salted",
  "Cheese",
  "Caramel",
  "Spicy"
  };
  const float popcornPrices[POPCORN_COUNT] = {3.00, 4.50, 3.50, 5.00};


  logic(films, prices, popcorns, popcornPrices, drinks, drinksPrices);

  return 0;
}