import random
import threading
import time
from tabulate import tabulate
import os


class Examiner:
    def __init__(self, name, gender):
        self.name = name
        self.gender = gender
        self.current_student = "-"
        self.total_students = 0
        self.failed = 0
        self.time_work = 0


class Student:
    def __init__(self, name, gender):
        self.name = name
        self.gender = gender
        self.status = "Очередь"
        self.time_pass = 0


class Question:
    def __init__(self, text):
        self.text = text
        self.score = 0


class Report:
    def __init__(self, examiners, students, questions, time):
        self.examiners = examiners
        self.students = students
        self.questions = questions
        self.time = time

    def students_and_exemeners(self):
        table_students = [[student.name, student.status] for student in self.students]
        status_order = {"Очередь": 0, "Экзамен": 0, "Сдал": 1, "Провалил": 2}
        table_students.sort(key=lambda x: status_order.get(x[1], 3))

        table_examiners = [
            [
                examiner.name,
                examiner.current_student,
                examiner.total_students,
                examiner.failed,
                examiner.time_work,
            ]
            for examiner in self.examiners
        ]

        return table_students, table_examiners

    def print_status_student(self):
        table_students, table_examiners = self.students_and_exemeners()
        total_students = sum(
            [1 for student in table_students if student[1] == "Очередь"]
        )

        print(tabulate(table_students, headers=["Студент", "Статус"], tablefmt="grid"))
        print()
        print(
            tabulate(
                table_examiners,
                headers=[
                    "Экзаменатор",
                    "Текущий студент",
                    "Всего студентов",
                    "Завалил",
                    "Время работы",
                ],
                tablefmt="grid",
                floatfmt=".2f",
            )
        )
        print(f"Осталось в очереди: {total_students} из {len(self.students)}")
        print(f"Время с момента начала экзамена: {self.time:.2f}")
        print()

    def print_final(self):
        table_students, table_examiners = self.students_and_exemeners()
        print(tabulate(table_students, headers=["Студент", "Статус"], tablefmt="grid"))
        print()
        print(
            tabulate(
                [row[:1] + row[2:] for row in table_examiners],
                headers=[
                    "Экзаменатор",
                    "Всего студентов",
                    "Завалил",
                    "Время работы",
                ],
                tablefmt="grid",
                floatfmt=".2f",
            )
        )
        print(
            f"Время с момента начала экзамена и до момента и его завершения: {self.time:.2f}"
        )

        passed_students = [s for s in self.students if s.status == "Сдал"]
        if passed_students != []:
            min_time = min(s.time_pass for s in passed_students)
            print(
                f"Имена лучших студентов: {', '.join([s.name for s in passed_students if s.time_pass == min_time])}"
            )
        else:
            print("Никто не сдал")

        for ex in self.examiners:
            if ex.failed > 0:
                ex.percent = ex.total_students / ex.failed
            else:
                ex.percent = 0
        min_percent = min(ex.percent for ex in self.examiners)

        print(
            f"Имена лучших экзаменаторов: {', '.join([ex.name for ex in self.examiners if ex.percent == min_percent])}"
        )

        failed_students = [s for s in self.students if s.status == "Провалил"]
        if failed_students != []:
            min_time = min(s.time_pass for s in failed_students)
            print(
                f"Имена студентов, которых после экзамена отчислят: {', '.join([s.name for s in failed_students if s.time_pass == min_time])}"
            )
        else:
            print("Никого не отчислят")

        best_score = max(q.score for q in self.questions)
        print(
            f"Лучшие вопросы: {', '.join([q.text for q in self.questions if q.score == best_score])}"
        )

        failed = sum(ex.failed for ex in self.examiners)
        total = len(self.students)
        if ((failed / total) * 100) <= 85:
            print("Вывод: экзамен не удался")
        else:
            print("Вывод: экзамен удался")


class Exam:
    def __init__(self, examiners, students, questions):
        self.examiners = examiners
        self.students = students
        self.questions = questions

    def count_weight(self, n):
        phi = 1.618
        a = 1
        weights = []
        for _ in range(n - 1):
            weight = a / phi
            weights.append(weight)
            a -= weight

        weights.append(a)
        return weights

    def exam_pass(self, q_id, ex_g, st_g):
        id = []
        weights = []
        count_answer = 0

        for i in range(3):
            id.append((q_id * 3 + i) % len(self.questions))

        questions_for_exam = [self.questions[i].text for i in id]
        for question, i in zip(questions_for_exam, id):
            words = question.split()
            weights = self.count_weight(len(words))

            if st_g == "Ж":
                words = words[::-1]
            st_answer = random.choices(words, weights=weights, k=1)[0]

            if ex_g == "Ж" and st_g != "Ж":
                words = words[::-1]

            word = random.choices(words, weights=weights, k=1)[0]
            words.remove(word)
            ex_answers = [word]
            while random.random() < 1 / 3 and len(words) != 0:
                weights = self.count_weight(len(words))
                word = random.choices(words, weights=weights, k=1)[0]
                ex_answer = word
                words.remove(word)
                ex_answers.append(ex_answer)

            if st_answer in ex_answers:
                count_answer += 1
            else:
                count_answer -= 1

            r = random.random()

            if r < 1 / 8:
                res = "Сдал"
                self.questions[i].score += 1
            elif r < 3 / 8:
                res = "Провалил"
            elif count_answer > 0:
                res = "Сдал"
                self.questions[i].score += 1
            else:
                res = "Провалил"

            return res

    def exam(self, examiner, global_time):
        start = time.perf_counter()
        total_students = 0
        student_taken = self.students[0]

        while total_students < len(self.students):
            student_taken = None
            for student in self.students:
                if student.status == "Очередь":
                    student_taken = student
                    student.status = "Экзамен"
                    examiner.current_student = student.name
                    break

            if student_taken is None:
                break

            # os.system("cls" if os.name == "nt" else "clear")
            time_exam = random.randint(len(examiner.name) - 3, len(examiner.name) - 1)
            time.sleep(time_exam)
            examiner.time_work += time_exam

            student.status = self.exam_pass(
                examiner.total_students, examiner.gender, student.gender
            )

            if student.status == "Провалил":
                examiner.failed += 1

            examiner.total_students += 1
            student.time_pass = time_exam
            report = Report(
                self.examiners,
                self.students,
                self.questions,
                time.perf_counter() - global_time,
            )
            report.print_status_student()

            examiner.current_student = "-"

            if time.perf_counter() - start >= 30:
                time_lunch = random.randint(12, 18)
                time.sleep(time_lunch)
                start = 0

def read_files():
    with open("exercise1/examiners.txt", "r") as file:
        examiners = []
        for line in file.readlines():
            name, gender = line.strip().split()
            examiners.append(Examiner(name, gender))

    with open("exercise1/students.txt", "r") as file:
        students = []
        for line in file.readlines():
            name, gender = line.strip().split()
            students.append(Student(name, gender))

    with open("exercise1/questions.txt", "r") as file:
        questions = []
        for line in file:
            questions.append(Question(line.strip()))
    return examiners, students, questions

def main():
    examiners, students, questions = read_files()
    exam = Exam(examiners, students, questions)

    start = time.perf_counter()
    threads = []
    for examiner in examiners:
        thread = threading.Thread(
            target=exam.exam,
            args=(examiner, start,),
        )
        threads.append(thread)
        thread.start()

    for thread in threads:
        thread.join()

    os.system("cls" if os.name == "nt" else "clear")
    report = Report(examiners, students, questions, time.perf_counter() - start)
    report.print_final()


if __name__ == "__main__":
    main()