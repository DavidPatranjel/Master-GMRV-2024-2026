using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraFollow : MonoBehaviour
{
    public GameObject obj;
    [SerializeField]
    private float _distanceFromPlayer = 10;
    [SerializeField]
    private float _height = 3;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        transform.position = obj.transform.position - obj.transform.forward * _distanceFromPlayer;
        transform.LookAt(obj.transform.position);
        transform.position = new Vector3(transform.position.x, transform.position.y + _height, transform.position.z);
    }
}
