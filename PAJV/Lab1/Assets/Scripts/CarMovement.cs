using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.InputSystem;


public class CarMovement : MonoBehaviour
{
    public Rigidbody rigidbidy;
    public Lab1 playerControl;
    InputAction move;
    Vector2 moveDir = Vector2.zero;

    public void Awake()
    {
        playerControl = new Lab1();
    }
    private void OnEnable()
    {
        move = playerControl.Player.Move;
        move.Enable();
    }

    private void OnDisable()
    {
        move.Disable();
    }
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        //moveDir = new Vector3(rigidbidy2D.).normalized;
        moveDir = move.ReadValue<Vector2>();
        Debug.Log(moveDir);
        rigidbidy.velocity = new Vector3(5.0f * moveDir.x, 0.0f, 5.0f * moveDir.y);
    }
}
