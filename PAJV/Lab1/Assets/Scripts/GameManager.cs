using UnityEngine;
using TMPro;

public class GameManager : MonoBehaviour
{
    private float timeElapsed;
    private bool isPaused = true;  // Start the game in a paused state
    public TMP_Text timerText;     // Reference to the TMP Text component
    public GameObject gameCanvas;  // Canvas for the game elements
    public GameObject pauseCanvas; // Canvas for the pause menu
    public GameObject otherCanvas1; // Other canvas used in the game
    public GameObject otherCanvas2; // Another canvas used in the game

    void Start()
    {
        // Start with the game paused, showing only the pause menu
        ActivatePauseCanvas();
        timeElapsed = 0f;
    }

    void Update()
    {
        // Toggle pause state when space is pressed
        if (Input.GetKeyDown(KeyCode.Space))
        {
            TogglePause();
        }

        // Reset the timer when R is pressed
        if (Input.GetKeyDown(KeyCode.R) && isPaused)
        {
            ResetTimer();
        }

        // Update the timer only when the game is not paused
        if (!isPaused)
        {
            timeElapsed += Time.deltaTime;

            // Calculate minutes, seconds, and milliseconds
            int minutes = Mathf.FloorToInt(timeElapsed / 60F);
            int seconds = Mathf.FloorToInt(timeElapsed % 60F);

            // Format the time and update the TMP text
            string timeFormatted = string.Format("{0:00}:{1:00}", minutes, seconds);
            timerText.text = timeFormatted;  // Display on the TMP text component
        }
    }

    void TogglePause()
    {
        isPaused = !isPaused;  // Toggle pause state

        if (isPaused)
        {
            ActivatePauseCanvas();
        }
        else
        {
            ActivateGameCanvas();
        }
    }

    // Private method to activate the pause canvas and deactivate game canvases
    private void ActivatePauseCanvas()
    {
        gameCanvas.SetActive(false);
        otherCanvas1.SetActive(false);
        otherCanvas2.SetActive(false);
        pauseCanvas.SetActive(true);
    }

    // Private method to activate the game canvases and deactivate pause canvas
    private void ActivateGameCanvas()
    {
        gameCanvas.SetActive(true);
        otherCanvas1.SetActive(true);
        otherCanvas2.SetActive(true);
        pauseCanvas.SetActive(false);
    }

    // Private method to reset the timer
    private void ResetTimer()
    {
        timeElapsed = 0f;  // Reset the time elapsed
        timerText.text = "00:00";  // Reset the displayed text
    }
}
