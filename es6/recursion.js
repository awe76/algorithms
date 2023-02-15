// Input:
const input = {
    "id": 111,
    "projectId": 123,
    "type": "TypeA",
    "children": {
        "typesB": [
            {
                "id": 222,
                "projectId": 123,
                "type": "TypeB"
            }
        ],
        "typesC": [
            {
                "id": 333,
                "projectId": 123,
                "type": "TypeC",
                "children": {
                    "typesD": [
                        {
                            "id": 444,
                            "projectId": 123,
                            "type": "TypeD"
                        }
                    ],
                    "typesX": [
                        {
                            "id": 555,
                            "projectId": 123,
                            "type": "TypeX",
                            "children": {
                                "typesD": [
                                    {
                                        "id": 666,
                                        "projectId": 123,
                                        "type": null
                                    }
                                ]
                            }
                        }
                    ]
                }
            }
        ]
    }
} 

function flatten({id, projectId, type, children}, result) {
    const current = {
        id,
        projectId,
        type
    };

    result.push(current);

    if (children) {
        for (key of Object.keys(children)) {
            for (item of children[key]) {
                flatten(item, result);
            }
        }
    }
}

function run(input) {
    const output = [];
    flatten(input, output);
    return output;
}

const output = run(input);
console.log(output);


