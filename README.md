Robert Final Report:

    what were the initial goals for this project:

        my initial goals for this project were to create a simple program that logs new guests and 
        then also tracks what the price of the room that they will be staying in.
        I continued to work on this project and decided to add a deletion feature so that you did not have to
        close the program so often, these were the hardest to program due to my visual studio application 
        not having the capability of using the rename function, this lead me to needing another temporary txt
        file that logs what the new file will look like without that specified guest and then overwrites
        the original text file. I am sure that there are easier ways of doing this although I have not found 
        any reasonable ways yet.

        another goal I wanted was to add a list function so that whenever you type 3, it would display all of the current
        guests within your txt file, I would have liked learning how to use a vector variable and maybe I would use a .dat file
        in order to possibly make it work, this would make the list update in real time although i'm sure it would be extremely
        resource expensive and make the program much slower.

        one of my goals were to make the user interface as straight forward and easy to read as possible, in order to achieve this
        I needed to make methods that rendered the specified scene that I wanted to create, I think that not only does this make
        the code to read but also allows any users that are not me, capable of reading it. I am still currently working on some
        in order to make it consistent through out the entire experience.

    what works:
        Currently, all of the features are working, although I may want to make some work better.
        for example, I would like to make the remove guest feature more efficient but I have not found
        a way quite yet in order to execute that.

        I had created a custom class to render any of the user interfaces, which I find to be much easier
        to read, and also much easier to call upon them since I know where to find them.

        I had created a user class that handles all of the user inputs, along with handling the file systems.
        there are several methods put here, such as creating a new account within the user input method,
        deleting an account within the removeGuest method, there is also a list that reads from the guests.txt file
        and lists everything that it finds, this makes it so that it only reads what was last written to it though.

        To dive deeper on the remove guest function because it is a very complex method, it first checks to make sure the 
        files are open or else it will instantly just return an error, this really only happens when someone or something deletes the file
        it is trying to access so in regular use cases it should never return an error. after checking that, it finds the specified users name
        which than it overwrites it within the temp.txt file in order to create what the latest text file will now be.
        after this temp.txt wipes the guests file and then pastes whatever is within it in order to create the most recent save of it.
        this is one of my most complex methods I have made so far, and a lot of research went into this method.

        the list method was also semi difficult the way it works is nearly the same as removing a guest in the way it reads files. 
        I wrote the same while loop as in the removeGuest method, although I set it != to string::npos rather than one specific name that will be inputted later.
        it then also displays everything found underneath that and once it finds an empty space it places a bunch of dashes in between in 
        order to sperate each account that way it is more readable for the user.

        for the getUserInput1 method, I decided to add the 1 after the name because I had thought I would make more within different user interfaces.
        this method works as both obtaining the user input through switch case logic, the method also acts as a creation tool for new guests.

    What features would be nice:
        I was considering adding a whole new c++ file attached that would manage banking, and give each individual person a bank identification
        obviously I did not go through with it because the timing left on the project was just not going to work.

        another feature that could be cool is possibly playing with vectors in order to show the user in real time what is happening to the file.

    Could you have done certain sections of the project differently (perhaps better?):
        of course I can, generally I like to stay away from multi dimensional arrays and for loops. although they are very nice to use, they are generally inefficient.
        I probably would have also worked on the getUserInput1 method a little more if I had the chance because it looks way too bloated.

    overall, I find that this was one of my most interesting projects yet and I will make sure to continue on my path of c++!
