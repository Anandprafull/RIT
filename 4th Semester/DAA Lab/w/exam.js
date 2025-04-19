
document.addEventListener('DOMContentLoaded', function() {
    const examForm = document.getElementById('examForm');
    const resultDiv = document.getElementById('result');
    const timerDisplay = document.getElementById('timer');
    const progressBar = document.getElementById('progress-bar');
    const warnings = document.querySelectorAll('.warning');
    
    // Correct answers
    const correctAnswers = {
    q1: 'java',
    q2: 'Object',
    q3: 'AWT',
    q4: 'Multiple Inheritance'
    };
    
    // Timer setup (10 minutes)
    let timeLeft = 600; // 10 minutes in seconds
    const timer = setInterval(updateTimer, 1000);
    
    function updateTimer() {
    const minutes = Math.floor(timeLeft / 60);
    const seconds = timeLeft % 60;
    timerDisplay.textContent = `Time remaining: ${minutes}:${seconds < 10 ? '0' : ''}${seconds}`;
    
    if (timeLeft <= 0) {
    clearInterval(timer);
    autoSubmit();
    } else {
    timeLeft--;
    }
    }
    
    function updateProgress() {
    
    let answered = 0;
    for (let i = 1; i <= 4; i++) {
    if (document.querySelector(`input[name="q${i}"]:checked`)) {
    answered++;
    }
    }
    const progress = (answered / 4) * 100;
    progressBar.style.width = `${progress}%`;
    }
    
    function autoSubmit() {
    // Auto-select random answers for unanswered questions
    for (let i = 1; i <= 4; i++) {
    const questionName = 'q' + i;
    if (!document.querySelector(`input[name="${questionName}"]:checked`)) {
    const options = document.querySelectorAll(`input[name="${questionName}"]`);
    const randomOption = options[Math.floor(Math.random() * options.length)];
    randomOption.checked = true;
    }
    }
    examForm.dispatchEvent(new Event('submit'));
    }
    
    // Form submission
    examForm.addEventListener('submit', function(e) {
    e.preventDefault();
    clearInterval(timer);
    
    // Validate all questions are answered
    let allAnswered = true;
    for (let i = 1; i <= 4; i++) {
    const questionName = 'q' + i;
    const selectedOption = document.querySelector(`input[name="${questionName}"]:checked`);
    
    if (!selectedOption) {
    document.getElementById('w' + i).style.display = 'block';
    allAnswered = false;
    } else {
    document.getElementById('w' + i).style.display = 'none';
    }
    }
    
    if (!allAnswered) {
    return;
    }
    
    // Calculate score
    let score = 0;
    for (let i = 1; i <= 4; i++) {
    const questionName = 'q' + i;
    const selectedOption = document.querySelector(`input[name="${questionName}"]:checked`);
    
    if (selectedOption.value === correctAnswers[questionName]) {
    score++;
    selectedOption.parentElement.parentElement.classList.add('correct');
    } else {
    selectedOption.parentElement.parentElement.classList.add('incorrect');
    // Highlight correct answer
    const correctOption = document.querySelector(`input[name="${questionName}"]
    [value="${correctAnswers[questionName]}"]`);
    correctOption.parentElement.parentElement.classList.add('correct');
    }
    }
    
    // Display result
    resultDiv.style.display = 'block';
    resultDiv.innerHTML = `
    <h2>Exam Results</h2>
    
    <p>Thank you for taking the online exam!</p>
    <p>Your score is: ${score}/4</p>
    <p>Percentage: ${(score/4*100).toFixed(0)}%</p>
    `;
    
    // Store results in localStorage
    const examResults = JSON.parse(localStorage.getItem('examResults') || '[]');
    examResults.push({
    date: new Date().toLocaleString(),
    score: score,
    percentage: (score/4*100).toFixed(0) + '%'
    });
    localStorage.setItem('examResults', JSON.stringify(examResults));
    
    // Disable form after submission
    document.querySelectorAll('input[type="radio"]').forEach(radio => {
    radio.disabled = true;
    });
    });
    
    // Reset form
    examForm.addEventListener('reset', function() {
    resultDiv.style.display = 'none';
    document.querySelectorAll('.question').forEach(question => {
    question.classList.remove('correct', 'incorrect');
    });
    warnings.forEach(warning => {
    warning.style.display = 'none';
    });
    document.querySelectorAll('input[type="radio"]').forEach(radio => {
    radio.disabled = false;
    });
    
    // Reset timer
    
    clearInterval(timer);
    timeLeft = 600;
    updateTimer();
    timer = setInterval(updateTimer, 1000);
    });
    });