int LED = 3;
void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    while (! Serial);
    Serial.println("Enter 1 for Encryption or enter 0 for Decryption"); //Selection Option
    pinMode(LED, OUTPUT);
}

int choice; //Variable used for selection
  
void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0) // For choice
  {
    choice = Serial.parseInt();
    if (choice == 1) //If user enters a 1 then do encryption
    {
      Serial.println("You have selected to encrypt something");
      while (!Serial.available() > 0){};
      while (Serial.available() > 0)
      {
       String text = Serial.readString();
       Serial.println("This is what you have selected to encrypt: " + text);
       Serial.print("This is the encryption: "); 
       encrypt(text); //Call encrypt function to encrypt the text
      }
    }

    else if (choice == 0) //If user enters a 0 then do decryption
    {
      Serial.println("You have selected to decrypt something");
      while (!Serial.available() > 0){};
      while (Serial.available() > 0)
      {
      String text = Serial.readString();
      Serial.println("This is what you have selected to decrypt: " + text);
      Serial.print("This is the decryption: ");
      decrypt(text); //Call decrypt function to decrypt text
      }
    }

    else
    {
      Serial.println("Enter either a 1 for Encryption or 0 for Decryption");     
    }
  }
}

char one[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'}; //First char array on keyboard
char two[] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'}; //Second char arry on keyboard
char three[] = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};    //Third char array on keyboard
char four[] = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};               //Fourth char array on keyboard

void encrypt(String text) //Encytption function
{
  for (int i = 0; i <= text.length(); i++) //Run loop until the length of the String
  {
    for (int k = 0; k < sizeof(one); k++) //Runs the array until the size of the one array
    {
      if (text.charAt(i) == one[0]) 
      {
        text.setCharAt(i, '0'); //If the number is 1 move it to 0
        break;
      }
      else if (text.charAt(i) == one[k])
      {
        text.setCharAt(i, one[k-1]); //Everything else gets moved back 1
        break;
      }
    }
    for (int k = 0; k < sizeof(two); k++) //Runs the array until the size of the two array
    {
      if (text.charAt(i) == two[0]) 
      {
        text.setCharAt(i, 'p'); //If letter is q move to p
        break;
      }
      else if (text.charAt(i) == two[k]) 
      {
        text.setCharAt(i, two[k-1]); //All other letters get moved back one
        break;
      }
    }
    for (int k = 0; k < sizeof(three); k++) //Runs the array until the size of the three array
    {
      if (text.charAt(i) == three[0]) 
      {
        text.setCharAt(i, 'l'); //If letter is a move to l
        break;
      }
      else if (text.charAt(i) == three[k]) 
      {
        text.setCharAt(i, three[k-1]); //All other letters get moved back one
        break;
      }
    }
    for (int k = 0; k < sizeof(four); k++) //Runs the array until the size of the four array
    {
      if (text.charAt(i) == four[0]) //If letter is z move to m
      {
        text.setCharAt(i, 'm');
        break;
      }
      else if (text.charAt(i) == four[k])
      {
        text.setCharAt(i, four[k-1]); //All other letters get moved back one
        break;
      }
    }
  }
    Serial.println(text);  //Display encryption
    String textnew = text; //Store inside new text
    morse(textnew);        //Call morse function to display message in morse code
}

void decrypt (String text) //Decryp function, does the exact opposite of the encrypt function
{
  for (int i = 0; i <= text.length(); i++) //Run loop until the length of the String
  {
    for (int k = 0; k < sizeof(one); k++) //Runs the array until the size of the one array
    {
      if (text.charAt(i) == one[9]) //If the number is 0 move it to 1
      {
        text.setCharAt(i, '1');
        break;
      }
      else if (text.charAt(i) == one[k]) 
      {
        text.setCharAt(i, one[k+1]); //All other numbers get moved forward one
        break;
      }
    }
    for (int k = 0; k < sizeof(two); k++) //Runs the array until the size of the two array
    {
      if (text.charAt(i) == two[9]) //If letter is p move it to q
      {
        text.setCharAt(i, 'q');
        break;
      }
      else if (text.charAt(i) == two[k])
      {
        text.setCharAt(i, two[k+1]); //All other letters get moved forward one
        break;
      }
    }
    for (int k = 0; k < sizeof(three); k++) //Runs the array until the size of the three array
    {
      if (text.charAt(i) == three[8]) //If letter is l move it to a
      {
        text.setCharAt(i, 'a');
        break;
      }
      else if (text.charAt(i) == three[k])
      {
        text.setCharAt(i, three[k+1]); //All other letters get moved forward one
        break;
      }
    }
    for (int k = 0; k < sizeof(four); k++) //Runs the array until the size of the four array
    {
      if (text.charAt(i) == four[6]) //If the letter is m move it to z
      {
        text.setCharAt(i, 'z');
        break;
      }
      else if (text.charAt(i) == four[k])
      {
        text.setCharAt(i, four[k+1]); //All other letters get moved forward one
        break;
      }
    }
  } 
    Serial.println(text);  //Display decryption
    String textnew = text; //Store inside new variable
    morse(textnew);        //Send new vaiable to morse function
}
//Variables used in the functions below
char* morseLetters[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",".---", "-.-", ".-..", "--",     //a - m in morse
                        "-.", "---", ".--.", "--.-", ".-.","...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." }; //n - z in morse
char* morseNumbers[] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};     //0 - 9 in morse
int dot = 200;

void morse (String textnew) //Morse code function called here
{
  Serial.println("Translating in morse code by LED: ");
  for(int i = 0; i <= textnew.length(); i++)
  {
    if (textnew.charAt(i) >= 'a' && textnew.charAt(i) <= 'z')
    { 
      charId(morseLetters[textnew.charAt(i) - 'a']);
    }
    else if(textnew.charAt(i) >= '0' && textnew.charAt(i) <= '9') 
    {
      charId(morseNumbers[textnew.charAt(i) - '0']);
    }
    else if(textnew.charAt(i) == ' ') 
    {
      delay(dot * 4);
    }
    
  }
}

void charId(char* character) //Take two char morse array
{
  int i = 0;
  while(character[i] != '\0') 
  {
    flash(character[i]); //Call flash
    i++;
  }
  delay(dot * 3);
}

void flash(char id) //Flash led based on the dot or dash sequence
{
  digitalWrite(LED,HIGH);
  if (id == '.') 
  {
  delay(dot);          
  }
  else 
  {
    delay(dot * 3);          
  }
  digitalWrite(LED,LOW);
  delay(dot);
}
