
public class PhilipHobby_Answer {

    public static void main(String[] args) {
        int[][] input = {
                {1, 0, 1, 0, 1, 0, 1},
                {1, 1, 1, 1, 1, 0, 1},
                {1, 1, 1, 0, 1, 1, 1},
                {0, 0, 0, 0, 0, 0, 0},
                {1, 0, 1, 1, 1, 1, 1}
                }; //expected output = 3 islands
        int[][] answer = new int[input.length][input[0].length];
        boolean[] listOfIslands = new boolean[45000];
        int labelCounter = 1;
        
        for (int i = 0; i < input.length; i++) {
            for (int j = 0; j < input[i].length; j++) {
                if (answer[i][j] == 0) { // haven't tested this cell yet
                    if (input[i][j] == 1) {//this cell is land
                        answer[i][j] = labelCounter;
                        listOfIslands[labelCounter] = true;
                        labelCounter++; 
                    }
                }
                //Below this tests UP.
                if (i - 1 >= 0) {//not out of scope
                    if (input[i][j] == 1) {//only test if this LAND is connected to more land——do not do this for Ocean
                        if (answer[i-1][j] > answer[i][j]) {//thought to have been a different island, but is not
                            listOfIslands[answer[i-1][j]] = false; //"delete" island from list   
                            answer[i-1][j] = answer[i][j]; //island label for previous cell is now current, earlier label                             
                        }
                    }
                }
                
                //below this tests to the RIGHT
                if (j + 1 < input[i].length) { // not out of scope
                    if (input[i][j + 1] == 1) { // i.e. this cell is land
                        if (answer[i][j + 1] == 0) { //this cell hasn't been tested yet
                            answer[i][j + 1] = answer[i][j]; //this cell is part of the island of the previous cell!
                        }
                        else {//this cell has already been tested 
                            if ((input[i][j] == 1) && (answer[i][j + 1] > answer[i][j])) {//thought to have been a different island, but is not
                                listOfIslands[answer[i][j + 1]] = false;
                                answer[i][j + 1] = answer[i][j]; //island label for previous cell is now current, earlier label
                            }
                        }
                    }
                } 
                // Below this tests BELOW
                if (i + 1 < input.length) { // not out of scope
                    if (input[i + 1][j] == 1) { // i.e. this cell is land
                        if (answer[i + 1][j] == 0) { //this cell hasn't been tested yet
                            answer[i + 1][j] = answer[i][j]; //this cell is part of the island of the previous cell!
                        }
                        else {//this cell has already been tested 
                            if ((input[i][j] == 1) && (answer[i + 1][j] > answer[i][j])) {//thought to have been a different island, but is not
                                listOfIslands[answer[i + 1][j]] = false;
                                answer[i + 1][j] = answer[i][j]; //island label for previous cell is now current, earlier label
                            }
                        }
                    }
                }                
            }               
        }
        int islandCounter = 0;
        
        for (int s = 0; s < listOfIslands.length; s++){
            if (listOfIslands[s] == true) {
                islandCounter++;
            }
        }
        System.out.print(islandCounter + " islands.");
    }
}
