To get this project locally you need to download Unity, and download git, with git LFS.
After all this is done create a local account with git in your console commands like so:

```
git config --global user.name "John Doe"
git config --global user.email johndoe@example.com

```

After this make sure you are standing inside a folder (in the console) where you would like the project to exist. 
After you can run the command: 

```
git clone https://github.com/RyuTribal/Project_GJ.git

```

## Git Commands

To create a branch:
```
git branch your-branch-name
```
To switch branches:
```
git checkout your-branch-name
```
To save changes made to a file:
```
git add .
```

To finalize your changes (no going back):
```
git commit -m "A useful message for the other developers about what changes you made"
``` 

To push code to a branch:
```
git push origin your-branch-name
```

To pull new changes from a branch:
```
git pull origin your-branch-name
```
