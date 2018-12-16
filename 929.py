def numUniqueEmails(emails):
    """
    :type emails: List[str]
    :rtype: int
    """
    bag = set()
    for email in emails:
        localname = email.split('@')[0]
        domainname = email.split('@')[1]
        localname = localname.split('+')[0]
        print(localname)
        localname = localname.replace('.','')
        name = localname + '@' + domainname
        print(name)
        bag.add(name)
    return len(bag)


emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]        
print(numUniqueEmails(emails))