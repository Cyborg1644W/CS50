from openai import OpenAI

# 1. Initialize with xAI's details
client = OpenAI(
    api_key="", 
    base_url="https://api.groq.com/openai/v1"
)

# 2. Use the standard Chat Completion method
response = client.chat.completions.create(
    model="llama-3.3-70b-versatile", 
    messages=[
        {"role": "user", "content": "Create a list of Random Name"}
    ]
)

# 3. Print the result
print(response.choices[0].message.content)