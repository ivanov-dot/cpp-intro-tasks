# cpp-intro-tasks
C++ beginner exercises: Git basics, conditionals, and loops.

🧭 Част 1: Въведение в системи за контрол на версиите (Git и GitHub)
Задача 1. Създаване на GitHub проект

Създай нов GitHub репозиторий с име cpp-intro-tasks.

Клонирай го локално.

Добави файл README.md, в който опиши:

своето име,

целта на проекта,

какви задачи ще съдържа.

Качи (commit + push) файла в GitHub.

Задача 2. Работа с Git

Създай нов клон (branch) с име task-solutions.

Добави C++ файл task1.cpp (например празен main() с „Hello, Git!“).

Направи commit с подходящо съобщение (например „Добавен първи примерен файл“).

Изпрати промените (push) и направи Pull Request към основния клон.

💻 Част 2: Условни оператори (if, switch)
Задача 3. Проверка за четност

Напиши програма, която въвежда цяло число и отпечатва:

„Числото е четно“, ако се дели на 2;

„Числото е нечетно“ – в противен случай.

Задача 4. Най-голямо от три числа

Прочети три цели числа и изведи кое е най-голямото, използвайки само if и else if.

Задача 5. Калкулатор с оператор switch

Напиши проста калкулаторна програма:

Потребителят въвежда две числа и оператор (+, -, *, /).

Използвай switch за избор на операция и отпечатай резултата.

🔁 Част 3: Цикли (for, while, do-while)
Задача 6. Сума на първите N числа

Въведи цяло число N и намери сумата на числата от 1 до N чрез цикъл for.

Задача 7. Таблица за умножение

Използвай for цикъл, за да изведеш таблицата за умножение (от 1×1 до 10×10).

Задача 8. Факториел

Въведи число n и изчисли n! (факториела му) чрез цикъл while.

Задача 9. Броене на цифри

Въведи цяло число и преброй колко цифри има то, използвайки do-while.

Задача 10. Числа от Фибоначи

Изведи първите N числа от редицата на Фибоначи (0, 1, 1, 2, 3, 5, ...).
Подсказка: използвай два променливи за предишните стойности и цикъл for.

✅ Допълнително упражнение (по GitHub):

След всяка решена задача:

Създай нов файл (task3.cpp, task4.cpp, и т.н.);

Направи git add, git commit с описание;

Изпрати (push) в GitHub.
По този начин ще упражниш основния работен поток с контрол на версиите.


Here’s how to do Task 1 (“Create a GitHub project”) from start to finish.

🧭 Task 1: Create a GitHub repository and connect it locally
✅ Step 1 — Create a GitHub account (if you don’t have one yet)

Go to https://github.com
.

Sign in, or click Sign up to make a free account.

✅ Step 2 — Create a new repository

Once logged in, click your profile picture (top-right) → Your repositories → New.

Name it cpp-intro-tasks.

Optional: add a short description such as

“C++ beginner exercises: Git basics, conditionals, and loops.”

Check “Add a README file” (so it’s not empty).

Click Create repository.

✅ Step 3 — Clone it to your computer

If you have Git installed locally (you can check by running git --version in a terminal):

On the repository page, click the Code button → copy the HTTPS link (something like

https://github.com/YourUsername/cpp-intro-tasks.git


)

Open a terminal or Git Bash and navigate to where you want the folder to live:

cd path/to/your/folder


Clone the repo:

git clone https://github.com/YourUsername/cpp-intro-tasks.git


Go inside it:

cd cpp-intro-tasks

✅ Step 4 — Edit the README file

Open the folder in your code editor (VS Code, CLion, etc.).

Open README.md and write something like:

# C++ Intro Tasks
Author: Your Name  
Purpose: Practice with Git, conditionals, and loops in C++.  

Tasks:
1. Git & GitHub basics  
2. Conditional statements  
3. Loops

✅ Step 5 — Commit and push your changes

In the terminal inside your repo:

git add README.md
git commit -m "Add project description to README"
git push


Go back to GitHub in your browser — refresh the page.
You should now see your updated README with your text.

🎉 Done!
You’ve:

created a GitHub repository,

cloned it locally,

made a local change,

and pushed it to GitHub.


How to sign out and sign in to git in the terminal

Step 1: Check who’s currently signed in

Open your terminal and run:

git config --global user.name
git config --global user.email


This shows the user info Git uses for commits.
You can also check if GitHub credentials are cached by running:

git credential-cache exit


or simply try a git push — it will show which GitHub account it’s using.

🔒 Step 2: Sign out (remove old credentials)
🪟 On Windows

Run this in the terminal:

git credential-manager erase https://github.com


Or:

Open Windows Credential Manager

Go to Windows Credentials → Generic Credentials

Find anything that looks like git:https://github.com

Click Remove

🍎 On macOS
git credential-osxkeychain erase https://github.com


Or open Keychain Access → search for “github.com” → delete any saved GitHub tokens.

🐧 On Linux

If you’ve used the cache or the credential store:

git credential-cache exit
git credential-store --file ~/.git-credentials erase https://github.com

🔑 Step 3: Sign in again (add new credentials)

Next time you run git push, Git will ask for authentication again.
There are two recommended methods:

Option 1 — Use HTTPS with a Personal Access Token (PAT)

Go to https://github.com/settings/tokens
 → Fine-grained tokens or Classic tokens

Generate a new token with repo and workflow permissions.

Copy the token (you’ll only see it once).

Back in your terminal, when Git asks for:

Username: your_github_username
Password: <paste your token here>


✅ Done — Git will store it securely via the credential manager.

Option 2 — Use SSH (recommended if you use GitHub often)

Generate an SSH key if you don’t have one:

ssh-keygen -t ed25519 -C "your_email@example.com"


Copy your public key:

cat ~/.ssh/id_ed25519.pub


Go to GitHub → Settings → SSH and GPG keys → New SSH key

Paste it there.

Test the connection:

ssh -T git@github.com


You should see:

Hi yourusername! You've successfully authenticated...

✅ Step 4: Verify the new identity
git config --global user.name "Your New Name"
git config --global user.email "your_email@example.com"


and confirm:

git config --global --list
